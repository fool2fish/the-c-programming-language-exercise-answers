/* Exercise 3-4
 * In a two's complement number representation, 
 * our version of itoa does not handle the largest negative number, 
 * that is, the value of n equal to -(2^(wordsize-1)). 
 * Explain why not. 
 * Modify it to print that value correctly, 
 * regardless of the machine on which it runs.
 */


/*
 * Why not:
 *
 * assume that wordsize is 2, we can know:
 *   binary:  00 01 10 11
 *   integer:  0  1 -2 -1
 *
 * largest negative number is -2
 *
 * because -2 < 0, so line 6 `n = -n` will run
 *   n = -(-2) = 2
 *
 * in 2's complement number representation
 *   2 -> 10(binary) -> -2
 */

#include <stdio.h>
#include <string.h>

int getwordsize();
void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
  char s[1000];
  
  int i = 0;
  itoa(i, s);
  printf("%d to string is: %s\n", i, s);

  i = -128;
  itoa(i, s);
  printf("%d to string is: %s\n", i, s);

  i = 256;
  itoa(i, s);
  printf("%d to string is: %s\n", i, s);
  
  i = 1 << (getwordsize() - 1);
  itoa(i, s);
  printf("%d to string is: %s\n", i, s);
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

void itoa(int n, char s[]) {
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

  s[i] = '\0';

  reverse(s);
}





