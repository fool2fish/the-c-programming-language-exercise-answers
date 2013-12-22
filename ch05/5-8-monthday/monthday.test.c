#include <assert.h>
#include <stdio.h>
#include "monthday.h"

int main(int argc, char *argv[]) {
  int m;
  int d;

  monthday(0, 0, &m, &d);
  assert(m == 0 && d == 0);

  monthday(0, 367, &m, &d);
  assert(m == 0 && d == 0);

  monthday(0, 60, &m, &d);
  assert(m == 2 && d == 29);

  assert(dayofyear(0, -1, 0) == 0);

  assert(dayofyear(0, 13, 1) == 0);

  assert(dayofyear(0, 12, 32) == 0);

  assert(dayofyear(2013, 2, 13) == 44);
}
