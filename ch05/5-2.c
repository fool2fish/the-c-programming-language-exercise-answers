// gcc ch05/5-2.c ch04/getch.c

/* Exercise 5-2
 * Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 */

#include <stdio.h>
#include <ctype.h>
#include "../ch04/getch.h"

int getfloat(double *p);

int main() {
  double i;
  if (getfloat(&i)) {
    printf("Found float: %g\n", i);
  } else {
    printf("Not fount float.\n");
  }
}

int getfloat(double *p) {
  int c, sign, nextc, power = 1;

  while (isspace(c = getch()));

  if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
    ungetch(c);
    return 0;
  }

  sign = c == '-' ? -1 : 1;

  if (c == '-' || c == '+') {
    nextc = getch();
    if (isdigit(nextc)) {
      c = nextc;
    } else {
      ungetch(nextc);
      ungetch(c);
      return 0;
    }
  }

  for (*p = 0.0; isdigit(c); c = getch()) {
    //printf("--> %c\n", c);
    *p = 10.0 * *p + (c - '0');
  }


  if (c == '.') {
    //printf("==> %c\n", c);
    c = getch();
  }

  for (; isdigit(c); c = getch()) {
    //printf("--> %c\n", c);
    *p = 10.0 * *p + (c - '0');
    power = power * 10.0;
  }

  *p = sign * *p / power;
  
  if (c != EOF) {
    ungetch(c);
  }

  return c;
}
