#include <stdlib.h>

#define MAXLINE 100
#define TABING  8

void settab(int argc, char *argv[], int *tab) {
  int i;
  int p;
  if (argc <= 1) {
    for (i = 0; i < MAXLINE; i++) {
      tab[i] = i % TABING == 0 ? 1 : 0;
    }
  } else {
    for (i = 1; i < MAXLINE; i++) {
      tab[i] = 0;
    }
    while (--argc) {
      p = atoi(*++argv);
      if (p > 0 && p <= MAXLINE) {
        tab[p] = 1;
      }
    }
  }
}
