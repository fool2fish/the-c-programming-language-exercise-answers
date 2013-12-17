#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "strcat.h"

int main(int argc, char *argv[]) {
  char s[100] = {'a', 'b', '\0'};
  char t[100] = {'c', 'd', '\0'};

  printf("%s\n", s);
  assert(!strcmp(s, "abcd"));
}
