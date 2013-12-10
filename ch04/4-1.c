/* Exercise 4-1
 * Write the function strindex(s,t) 
 * which returns the position of the rightmost occurrence of t in s, 
 * or -1 if there is none.
 */

#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main() {
  printf("strindex(\"abcabc\", \"ab\") -> %d\n", strindex("abcabc", "ab"));
  printf("strindex(\"abcabc\", \"def\") -> %d\n", strindex("abcabc", "def"));
}

int strindex(char s[], char t[]) {
  int lens = strlen(s);
  int lent = strlen(t);

  int i;
  int j;
  int k;

  for (i = lens - lent; i >= 0; i--) {
    for (j = 0, k = i; t[j] != '\0' && t[j] == s[k]; j++, k++)
      ;
    if (j > 0 && t[j] == '\0') {
      return i;
    }
  }

  return -1;
}
