/*
 * Exercise 1-5
 * Modify the temperature conversion program to print the table in reverse order,
 * that is, from 300 degrees to 0.
 */

#include <stdio.h>

int fahr2celsius(int degree) {
  return 5 * (degree - 32) / 9;
}

int printFahrList(int start, int end, int step, int withHead) {
  if (start <= end && step < 0 || start >= end && step > 0 || step == 0) {
    printf("params error!\n");
    return 1;
  }

  if (withHead) {
    printf("fahr\tcelsius\n");
  }

  int i = start;
  while (start <= end ? i <= end : i >= end) {
    printf("%d\t%d\n", i, fahr2celsius(i));
    i += step;
  }
}

int main() {
  printFahrList(300, 0, -20, 1);
}
