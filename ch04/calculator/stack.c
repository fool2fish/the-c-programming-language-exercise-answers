#include <stdio.h>

#define LEN 100

static int p = 0;
static double val[LEN];

void push(double n) {
  printf("push n: %g at idx: %d\n", n, p);
  if (p < LEN) {
    val[p++] = n;
  } else {
    printf("Error: stack full.");
  }
}

double pop() {
  if (p > 0) {
    return val[--p];
  } else {
    printf("Error: stack empty.");
    return 0.0;
  }
}

void swap() {
  if (p > 1) {
    double tmp = val[p - 1];
    val[p - 1] = val[p - 2];
    val[p - 2] = tmp;
  } else {
    printf("Error: on enough stack elements to swap.");
  }
}

double gettop() {
  return val[p - 1];
}

void clearstack() {
  p = 0;
}
