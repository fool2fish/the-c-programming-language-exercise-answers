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
