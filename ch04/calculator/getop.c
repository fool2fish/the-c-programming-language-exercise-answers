#include <stdio.h>
#include <ctype.h>

/*
 * Get token seperated by space from s
 * Return index if found or 0 if not found
 */
int getop(char s[], int i, char t[]) {
  int j = 0;
  int c;

  for (; isspace(s[i]); i++);

  for (; !isspace(c = s[i]) && c != '\0'; i++, t[j++] = c);
  t[j] = '\0';

  return j ? i : -1;
}


