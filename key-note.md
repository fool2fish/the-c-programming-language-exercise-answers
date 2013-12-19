### 函数和变量和作用域

file: a.c

```
static int fileScopeVariable = 1;  // 定义一个文件内可见的变量
int globalVariable = 2;
int anotherGloableVariable = 3;

static int fileScopeFunction() {return 1;} // 定义一个文件内可见的函数
int globalFunction() {return 2;}
int anothterGlobalFunction() {
  static int i = 0;  // 定义了一个一直占据存储空间的内部变量
  return i++;
}
```

file: a.h（将全局变量和函数声明在头文件中，省略 extern 关键字的使用）

```
#ifndef _A_H_
#define _A_H_

int globalVariable;
int globalFunction();

#endif
```

file: main.c

```
#include "a.h"

int main() {
  /*
   * 除了 "a.h" 中声明的一个全局变量和全局函数外
   * 实际上还可以访问到函数 anothterGlobalFunction()
   * 但不能访问到变量 anotherGloableVariable
   * 这跟单文件内变量必须先于使用前声明，而函数不用的表现一致
   */
}
```

**疑问：** 据上，头文件中无需声明全局函数，仅需声明全局变量和常量，但现实开发中不会这么做，为何？

### 字符串和数组

1. 声明

  ```
  char a[] = "abc";  // 声明了一个长度为4的字符数组
  char *s = "def";   // 声明了一个指向字符串 "def" 第一个字符的指针
  ```

2. 赋值

  ```
  a = "newabc"  // 错误！数组名不能进行赋值操作
  a++           // 错误！同上
  s = "newdef"  // 指针 s 指向新字符串 "newdef" 第一个字符
  s++           // 指针 s 指向其下一个字符，即 'e'
  ```

3. 函数调用

  ```
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

  所以，书上类似 `reverse(char s[])` 之类的函数实现，只能处理字符数组，而不能处理真正的字符串。