#include <stdio.h>

#define BUFSIZE 100

static char c;

int getch() {
  char rt = c ? c : getchar();
  c = '\0';
  return rt;
}

int ungetch(char ch) {
  if (c) {
    printf("Error: more than one char unget.\n");
    return 0;
  } else {
    c = ch;
    return 1;
  }
}
