/*
 * Exercise 5-3.
 * Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t)
 * copies the string t to the end of s.
 */

#include <string.h>

void strcat2(char s[], char t[]) {
  int i = strlen(s);
  char c;
  while ((c = *t) != '\0') {
    *(s + i++) = c;
    t++;
  }
  *(s + i) = '\0';
}
