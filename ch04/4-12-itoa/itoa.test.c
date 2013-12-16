#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "./itoa.h"

int main(int argc, char *argv[]) {
  char s[100];

  itoa(0, s);
  assert(!strcmp("0", s));

  itoa(-0, s);
  assert(!strcmp("0", s));

  itoa(1234, s);
  assert(!strcmp("1234", s));

  itoa(-1234, s);
  assert(!strcmp("-1234", s));

  return 0;
}
