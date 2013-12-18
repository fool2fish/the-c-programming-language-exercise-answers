#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "readlines.h"

#define MAX 100
int main(int argc, char *argv[]) {
  char *lineptr[MAX];
  int nlines = readlines(lineptr, MAX);
  assert(nlines == 4);
  assert(!strcmp(lineptr[0], "first line"));
  assert(!strcmp(lineptr[3], "last line"));

  printf("--- start write lines ---\n");
  writelines(lineptr, nlines);
}
