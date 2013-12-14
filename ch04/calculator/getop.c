#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/*
 * Get token seperated by space.
 * return 1 if get a token or return 0.
 */
int getop(char s[]) {
  int i, c;

  while (isspace(s[0] = c = getch()));

  if (c == EOF) {
    s[0] = '\0';
    return 0;
  }

  for (i = 1; !isspace(s[i] = c = getch()) && c != EOF; i++);
  s[i] = '\0';
  ungetch(c);

  return 1;
}


