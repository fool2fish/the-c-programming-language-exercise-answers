#include <stdio.h>

#include "tabpos.h"

void detab(int *tab) {
  int c;
  int p = 1;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      do {
        putchar('-');
      } while (!tabpos(p++, tab));
    } else if (c == '\n') {
      putchar(c);
      p = 1;
    } else {
      putchar(c);
      p++;
    }
  }
}
