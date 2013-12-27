#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "getlines.h"

#define MAXLINES 1000

int main(int argc, char *argv[]) {
  char *lines[MAXLINES];
  int len;
  if (len = getlines(lines, MAXLINES, stdin)) {
    assert(len == 3);
    assert(strcmp(lines[0], "line1\n") == 0);
    assert(strcmp(lines[1], "line2\n") == 0);
    assert(strcmp(lines[2], "line3\n") == 0);
  }
}
