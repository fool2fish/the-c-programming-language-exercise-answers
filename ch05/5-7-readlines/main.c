#include <stdio.h>

#include "readlines.h"
#include "qsort.h"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int main(int argc, char *argv[]) {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("Error: input too big to sort.\n");
    return 1;
  }
}
