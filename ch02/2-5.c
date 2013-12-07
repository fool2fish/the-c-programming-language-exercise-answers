/*
 * Exercise 2-5
 * Write the function any(s1,s2),
 * which returns the first location in a string s1 
 * where any character from the string s2 occurs, 
 * or -1 if s1 contains no characters from s2. 
 * (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */

#include <stdio.h>

int indexof(char s[], char c);
int any(char s1[], char s2[]);


int main() {
  printf("any(\"hello fool2fish!\", \"f2f\") -> %d\n", any("hello fool2fish", "f2f"));
  printf("any(\"hello fool2fish!\", \"yzx\") -> %d\n", any("hello fool2fish", "yzx"));
}


// This is not a effective way.
// We can sort s[] alphabetically and then find c by binary search.
int indexof(char s[], char c) {
  int i = 0;
  char ch;
  while((ch = s[i++]) != '\0') {
    if (ch == c) {
      return --i;
    }
  }
  return -1;
}

int any(char s1[], char s2[]) {
  int i = 0;
  char c;
  while ((c = s1[i++]) != '\0') {
    int idx = indexof(s2, c);
    if (idx != -1) {
      return --i;
    }
  }
  return -1;
}


