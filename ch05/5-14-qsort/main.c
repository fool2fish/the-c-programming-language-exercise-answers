#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "getlines.h"
#include "cmp.h"

#define MAXLINES 1000

enum sortRules { STR, DIR, NUM };

int main(int argc, char *argv[]) {
  int sortBy = STR;
  int reverse = 0;
  int caseSensitive = 1;
  FILE *stream = stdin;

  int c;
  while ((c = getopt(argc, argv, "dfnr")) != -1) {
    if (c == 'd') {
      sortBy = DIR;
    } else if (c == 'f') {
      caseSensitive = 0;
    } else if (c == 'n') {
      sortBy = NUM;
    } else if (c == 'r') {
      reverse = 1;
    } else if (c == '?') {
      if (isprint (optopt)) {
        fprintf(stderr, "Error: unknown option '%c'.\n", optopt);
      } else {
        fprintf(stderr, "Error: unkown character '\\x%x'.\n", optopt);
      }
    } else {
      abort();
    }
  }

  char *lines[MAXLINES];
  int len;
  if (len = getlines(lines, MAXLINES, stream)) {
    int (*cmp)(char *, char *);
    if (sortBy == STR) {
      cmp = caseSensitive ? strcmp : strcmpi;
    } else if (sortBy == DIR) {
      cmp = caseSensitive ? dircmp : dircmpi;
    } else {
      cmp = numcmp;
    }
    qsort2(lines, 0, len - 1, cmp, reverse);

    int i;
    for (i = 0; i < len; i++) {
      printf("%s", lines[i]);
    }
  }
}
