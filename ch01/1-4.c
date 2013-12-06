/*
 * Exercise 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>

int celsius2fahr(int degree) {
  return degree * 9 / 5 + 32;
}

int printFahrList(int start, int end, int step, int withHead) {
  if (start <= end && step < 0 || start >= end && step > 0 || step == 0) {
    printf("params error!\n");
    return 1;
  }

  if (withHead) {
    printf("celsius\tfahr\n");
  }

  int i = start;
  while (start <= end ? i <= end : i >= end) {
    printf("%d\t%d\n", i, celsius2fahr(i));
    i += step;
  }
}

int main() {
  printFahrList(-17, 148, 11, 1);
}
