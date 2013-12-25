#include <stdio.h>

#include "tabpos.h"

void entab(int *tab) {
  int c;
  int pos = 0;
  int space = 0;
  while ((c = getchar()) != EOF) {
    pos++;
    if (c == ' ') {
      space++;
    } else {
      if (c == '\t') {
        space = 0;
        while (!tabpos(pos, tab)) {
          pos++;
        }
        putchar('\\');
        putchar('t');
      } else if (c == '\n') {
        space = 0;
        pos = 0;
        putchar(c);
      } else {
        while (space > 0) {
          putchar('-');
          space--;
        }
        putchar(c);
      }
    }

    if (tabpos(pos, tab) && space > 0) {
      space = 0;
      putchar('\\');
      putchar('t');
    }
  }
}
