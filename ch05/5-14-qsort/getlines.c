#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int getlines(char *lines[], int nline, FILE *stream) {
  int i = 0;
  char s[MAXLINE];
  char *p;
  while(fgets(s, MAXLINE, stream) && i < nline) {
    p = malloc(strlen(s) + 1);
    strcpy(p, s);
    lines[i++] = p;
  }
  return i;
}
