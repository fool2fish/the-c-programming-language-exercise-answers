#include <stdlib.h>

#define MAXLINE 100
#define TABING  8

void settab(int start, int step, int *tab) {
  if (start < 0 || start >= MAXLINE) start = 0;
  if (step <= 0) step = 8;

  int i;
  for (i = 1; i < MAXLINE; i++) {
    tab[i] = 0;
  }

  while ((start += step) < MAXLINE) {
    tab[start] = 1;
  }
}
