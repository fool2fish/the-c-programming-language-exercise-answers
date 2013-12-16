#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "./reverse.h"

int main(int argc, char *argv[]) {
  char s1[4] = {'a', 'b', 'c', '\0'};

  reverse(s1);
  assert(!strcmp("cba", s1));

  char s2[1] = {'\0'};
  reverse(s2);
  assert(!strcmp("", s2));

  return 0;
}
