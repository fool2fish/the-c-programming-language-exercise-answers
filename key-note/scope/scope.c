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
