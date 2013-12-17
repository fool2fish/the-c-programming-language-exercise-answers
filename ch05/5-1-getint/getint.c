/* Exercise 5-1
 * As written, getint treats a + or - not followed by a digit as a valid representation of zero. 
 * Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

#include "./getch.h"

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()));

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1; 

  if (c == '+' || c == '-') {
    int nextc = getch();
    if (isdigit(nextc)) {
      c = nextc;
    } else {
      ungetch(nextc);
      ungetch(c);
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0'); 
  }

  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }

  return c;
}
