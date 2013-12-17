/* Exercise 5-4.
 * Write the function strend(s,t),
 * which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
 */

#include <string.h>

int strend(char s[], char t[]) {
  int lens = strlen(s);
  int lent = strlen(t);

  if (!lent || lens < lent) return 0;

  while (lent > 1) {
    if (*(t + lent--) != *(s + lens--)) {
      return 0;
    }
  }

  return 1;
}
