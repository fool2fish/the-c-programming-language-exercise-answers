#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "./getfloat.h"

int main(int argc, char *argv[]) {
  double d;

  assert(getfloat(&d));
  assert(d == 0.0);

  assert(getfloat(&d));
  assert(d == 0.0);

  assert(getfloat(&d));
  assert(d == 123.45);

  assert(getfloat(&d));
  assert(d == -123.45);

  assert(!getfloat(&d));
  assert(getch() == '+');

}
