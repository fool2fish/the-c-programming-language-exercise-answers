#include <stdio.h>
#include <stdlib.h>

#include "entab.h"
#include "settab.h"

#define MAXLINE 100

int main(int argc, char *argv[]) {
  int start = 0;
  int step = 8;
  while (--argc > 0) {
    char *s = *++argv;
    if (*s == '-') {
      start = atoi(++s);
    } else if (*s == '+') {
      step = atoi(++s);
    }
  }

  int tab[MAXLINE];
  settab(start, step, tab);

  entab(tab);
}
