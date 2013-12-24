#include <assert.h>
#include <stdio.h>
#include "../calculate.h"

int main(int argc, char *argv[]) {
  double rt = calculate(++argv, --argc);
  assert(rt == 14);
}
