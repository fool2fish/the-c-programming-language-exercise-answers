#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int p = 0;

int getch() {
  return p > 0 ? buf[--p] : getchar();
}

int ungetch(char c) {
  if (p >= BUFSIZE) {
    printf("error: buf is full.");
    return 0;
  } else {
    buf[p++] = c;
    return 1;
  }
}
