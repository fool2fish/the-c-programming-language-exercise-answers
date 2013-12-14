#include <stdio.h>

int getline2(char s[]) {
  static int c;
  int i = 0;

  if (c == EOF) {
    return 0;
  }

  while((c = getchar()) != '\n' && c != EOF) {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';

  return 1;
}
