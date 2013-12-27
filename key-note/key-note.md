### 待整理

- gcc 的使用
- 寄存器变量（p71）
- #define function() 的优势 (为确保正确的优先级，所有得参数都要用括号括起来，很烦人啊)
- #undefine 已定义的宏

---


### const

```
#include <stdio.h>
#include <string.h>

int main(){
  char s1[] = "a";
  char s2[] = "d";
  printf("%d\n", strcmp(s1, s2));      // -3
  printf("%d\n", strcmp("a", "d"));    // -1
}
```

疑问：为什么输出结果不一样？注意 `strcmp(const char *, const char *)` 的声明要求参数是 const。


### 初始化

在不进行显示初始化的情况下：

1. 外部变量和静态变量被初始化为 0。
2. 自动变量和寄存器变量的初值没有定义（即为无用信息，可能为任意值）。

初始化时：

1. 外部变量和静态变量的初始化表达式必须为常量表达式（[为什么？](http://blog.csdn.net/rosetta/article/details/6603370)）。
2. 自动变量和寄存器变量可以不是常量表达式。
3. 如果初始化表达式的个数比数组元素个数少，则不管该数组是外部变量、静态变量还是自动变量，剩余没有初始化表达式的元素都被初始化为 0。

#### 数组初始化

file: init-arr.c

```
#include <stdio.h>

int global[2];
int global2[2] = {1};

int main() {
  int local[2];
  int local2[2] = {1};
  printf("global[0]: %d\n", global[0]);
  printf("global2: {%d, %d}\n", global2[0], global2[1]);
  printf("local[0]: %d\n", local[0]);
  printf("local2: {%d, %d}\n", local2[0], local2[1]);
}
```

运行结果：

```
global[0]: 0
global2: {1, 0}
local[0]: 32767
local2: {1, 0}
```

#### 字符串数组全局变量初始化

file: init-global.c

```
#include <stdio.h>

char a[] = "a char list";
char *p = "a string const";
char *list[] = {a, p};

int main(){}
```

编译结果：

```
init-global.c:5: error: initializer element is not constant
init-global.c:5: error: (near initialization for ‘list[1]’)
```

疑问：为什么会报上面的错误？


### 函数和变量的作用域

file: scope/scope.c

```
#include <stdio.h>

static int fv = 1;  // 文件内可访问变量
int gv = 1;
int gv2 = 1;

static void foo() {  // 文件内可访问函数
  printf("foo()\n");
}

void bar() {
  printf("bar()\n");
}

void bar2() {
  printf("bar2()\n");
}
```

file: scope/scope.h

```
#ifndef _SCOPE_H_
#define _SCOPE_H_

int gv;
void bar();

#endif
```

file: scope/main.c

```
#include <stdio.h>
#include "scope.h"

// int gv2 = 2;
// 错误！重复定义全局变量
// ld: 1 duplicate symbol for architecture x86_64

extern int gv2;
// int gv2;
// 头文件中未声明，需先声明，再使用
// 疑问：为什么加不加 extern 都可以？

int main() {
  // int gv2 = 2;
  // 局部变量覆盖全局变量
  printf("gv: %d\n", gv);
  printf("gv2: %d\n", gv2); // 头文件中声明，可直接使用
  bar();
  bar2();  // 疑问：为什么不在头文件中声明也能访问？
}

```


### 多维数组作为参数传递给函数

```
void foo(char arr[][]) {...}  // 错误！type of formal parameter 1 is incomplete

void foo(char **arr) {...}    // 错误！passing argument 1 of ‘foo’ from incompatible pointer type

void foo(char arr[][100])     // 正确：arr 指向第一行（arr[0]）
                              //      程序需要知道行大小（100 * sizeof char）
                              //      不管是几维数组，只有第一维可以省略传递数组大小
                              //      不然怎么知道 arr + 1 指向哪里呢：）

void foo(char (*arr)[100])    // 正确：但鉴于其可读性和可维护性较差，推荐上面的写法
```


### 字符串和数组

1. 声明

  ```
  char v[4] = {'a', 'b', 'c', '\0'};  // 长度为4的字符数组
  char a[] = "abc";                   // 同上
  char *s = "def";                    // 指向字符串 "def" 第一个字符的指针
  ```

2. 赋值

  ```
  a = "newabc"  // 错误！数组名不能进行赋值操作
  a++           // 错误！同上
  s = "newdef"  // 指针 s 指向新字符串 "newdef" 第一个字符
  s++           // 指针 s 指向其下一个字符，即 'e'
  ```

3. 作为参数传递给函数

  ```
  #include <stdio.h>

  void foo(char s[]) {
    printf("%c\n", *++s);
  }

  int main() {
    char a[] = {'a', 'b', 'c', '\0'};
    foo(a);                    // 数组名作为参数传递给一个函数时
                               // 实际上传递的是该数组第一个元素的地址副本
                               // 于是可以对该副本进行赋值操作
    printf("%c\n", *++a);      // 错误！数组名不能进行赋值操作
  }
  ```

4. 修改字符元素

  ```
  #include <stdio.h>

  void bar(char *s) {
    s[0] = 'z';
    printf("%s\n", s);
  }

  int main() {
    char *s = "abc";
    s[0] = 'y';      // 错误！字符串不能被修改
    bar(s);          // 错误！虽然传递给 bar 的是一个地址副本
                     // 但其指向的仍然是字符串
  }
  ```

  所以，书上类似 `reverse(char s[])` 之类的函数实现，只能处理字符数组，而不能处理字符串常量。


### 命令行参数中的通配符

Unix 系统中，shell 脚本会自动对通配符（*）进行扩展，替换为当前目录下所有的文件和一级子目录列表。

例如下面计算后缀表达式的程序：

```
$ calculate 2 3 4 + *    // 错误！

$ calculate 2 3 4 + "*"  // 正确：单双引号均可阻止通配符扩展
```


### 函数参数的计算顺序

函数调用时，传入的参数求值顺序不定，因此当传入参数的求值顺序有要求，须在函数调用前求值完毕。

```
#include <stdio.h>

void foo(int a, int b, int c) {
  printf("%d, %d, %d\n", a, b, c);
}

int main() {
  int i = 0;
  foo(i++, i++, i++);  // 可能输出 "2, 1, 0"
}
```