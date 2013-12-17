#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "./getint.h"

int main(int argc, char *argv[]) {
  int i;

  assert(getint(&i));
  assert(i == 0);

  assert(getint(&i));
  assert(i == 0);

  assert(getint(&i));
  assert(i == 123);

  assert(getint(&i));
  assert(i == -123);

  assert(!getint(&i));
  assert(getch() == '+');

}
