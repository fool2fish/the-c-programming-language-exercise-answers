#include <stdio.h>

void _itoa(int n, char s[], int *p);

void itoa(int n, char s[]) {
  int idx = 0;
  _itoa(n, s, &idx);
  s[idx] = '\0';
}


void _itoa(int n, char s[], int *p) {
  int m = n % 10;
  n /= 10;

  if (n) {
    _itoa(n, s, p);
    s[(*p)++] = (m > 0 ? m : -m) + '0';
  } else {
    if (m >= 0) {
      int idx = *p;
      s[idx] = m + '0';
      (*p)++;
    } else {
      s[(*p)++] = '-';
      s[(*p)++] = -m + '0';
    }
  }
}




