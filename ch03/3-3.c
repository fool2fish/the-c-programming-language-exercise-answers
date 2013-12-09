/* Exercise 3-3 
 * Write a function expand(s1,s2) that 
 * expands shorthand notations like a-z in the string s1 
 * into the equivalent complete list abc...xyz in s2. 
 * Allow for letters of either case and digits, 
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
 * Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main() {
  char s1[] = "-a-c, e-c-a, a-a, a-Z, a-9\n-A-C, E-C-a, A-A, A-z, A-9\n-0-2, 4-2-0, 0-0, 0-z, 0-Z\n";
  char s2[1000];
  expand(s1, s2);
  printf("source string:\n%s\nresult string:\n%s\n", s1, s2);
}

void expand(char s1[], char s2[]) {
  char c;
  int i = 0;
  int j = 0;
  while ((c = s1[i]) != '\0') {
    char nextc = s1[i + 1];
    if (nextc == '-') {
      char thirdc = s1[i + 2];
      if (
          isdigit(c) && isdigit(thirdc) 
          ||
          isupper(c) && isupper(thirdc)
          ||
          islower(c) && islower(thirdc)
      ) {
        if (c < thirdc) {
          while (c <= thirdc) {
            s2[j++] = c;
            c++;
          }
        } else {
          while (c >= thirdc) {
            s2[j++] = c;
            c--;
          }
        }
        i += 3;
      } else {
        s2[j++] = s1[i++];
      }
    } else {
      s2[j++] = s1[i++];
    }
  }
  s2[j] = '\0';
}
