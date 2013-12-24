#include <stdio.h>
#include "detab.h"
#include "settab.h"

#define MAXLINE 100

int main(int argc, char *argv[]) {
  int tab[MAXLINE];

  settab(argc, argv, tab);
  /*
  int i = 0;
  for(; i < MAXLINE; i++) {
    printf("%d ", tab[i]);
  }*/
  entab(tab);
}
