/* Exercise 3-6
 * Write a version of itoa that accepts three arguments instead of two. 
 * The third argument is a minimum field width; 
 * the converted number must be padded with blanks on the left 
 * if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>

int getwordsize();
void reverse(char s[]);
void itoa(int n, char s[], int w);

int main() {
  char s[1000];
  
  int i = 0;
  int w = 8;
  itoa(i, s, w);
  printf("%d to string width %d is: %s\n", i, w, s);

  i = -128;
  w = 8;
  itoa(i, s, w);
  printf("%d to string width %d is: %s\n", i, w, s);

  i = 256;
  w = 16;
  itoa(i, s, w);
  printf("%d to string width %d is: %s\n", i, w, s);
  
  i = 1 << (getwordsize() - 1);
  w = 16;
  itoa(i, s, w);
  printf("%d to string width %d is: %s\n", i, w, s);
}

int getwordsize() {
  int i = 1;
  int j = 1;
  while ((i <<= 1) != 0) {
    j++;
  }
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int w) {
  int i = 0;
  int sign = n % 10;
  s[i++] = (sign < 0 ? -sign : sign) + '0';

  n /= 10;
  if (n < 0) {
    sign = n;
    n = -n;
  }

  while (n > 0) {
    s[i++] = n % 10 + '0';
    n /= 10;
  }

  if (sign < 0) {
    s[i++] = '-';
  }

  if (i < w) {
    while (w > i) {
      s[i++] = ' ';
    }
  }

  s[i] = '\0';

  reverse(s);
}





