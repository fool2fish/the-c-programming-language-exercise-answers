#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "cmp.h"

int main(int argc, char *argv[]) {
  char s[] = {'t', '\t', 'h', 'r', 'e', 'e', '\t', '\0'};
  char *arr[] = {"one", "TWO", "three", s};

  qsort2(arr, 0, 3, strcmp);
  assert(strcmp(arr[1], "one") == 0);
  assert(strcmp(arr[0], "TWO") == 0);
  assert(strcmp(arr[2], s) == 0);
  assert(strcmp(arr[3], "three") == 0);

  qsort2(arr, 0, 3, strcmpi);
  assert(strcmp(arr[0], "one") == 0);
  assert(strcmp(arr[3], "TWO") == 0);
  assert(strcmp(arr[1], s) == 0);
  assert(strcmp(arr[2], "three") == 0);

  qsort2(arr, 0, 3, dircmp);
  assert(strcmp(arr[1], "one") == 0);
  assert(strcmp(arr[0], "TWO") == 0);
  assert(strcmp(arr[2], s) == 0);
  assert(strcmp(arr[3], "three") == 0);

  qsort2(arr, 0, 3, dircmpi);
  assert(strcmp(arr[0], "one") == 0);
  assert(strcmp(arr[3], "TWO") == 0);
  assert(strcmp(arr[2], "three") == 0);
  assert(strcmp(arr[1], s) == 0);
}
