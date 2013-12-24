#include <stdio.h>

#include "tabpos.h"

int space = 0;

void entab(int *tab) {
  int c;
  int pos = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      space++;
      pos++;
      while ((c = getchar()) == ' ') {
        space++;
        pos++;
        if (tab[pos]) {
          space = 0;
          putchar('\\');
          putchar('t');
        }
      }
      if (c != ' ') {
        while(--space >= 0) {
          putchar(' ');
        }
        putchar(c);
        pos++;
      }
      if (c == EOF) {
        break;
      }
    } else if (c == '\t') {
      putchar('\\');
      putchar('t');
      while(!tab[++pos]);
    } else if (c == '\n') {
      putchar(c);
      space = 0;
      pos = 0;
    } else {
      putchar(c);
      pos++;
    }
  }
}
