#include <stdio.h>
#include <string.h>

#include "alloc.h"

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines) {
  int len, nlines = 0;
  char *p, line[MAXLEN];
  while (gets(line)) {
    len = strlen(line);
    if (nlines >= maxlines || !(p = alloc(len + 1))) {
      return -1;
    } else {
      strcpy(p, line);
      *(p + len) = '\0';
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}
