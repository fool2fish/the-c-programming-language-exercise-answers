#include <assert.h>
#include "../isnumfmt.h"

int main(int argc, char *argv[]) {
  assert(isnumfmt("0"));
  assert(isnumfmt("-1"));
  assert(isnumfmt("2."));
  assert(isnumfmt(".3"));
  assert(isnumfmt("4e5"));
  assert(isnumfmt("6E-7"));
  assert(!isnumfmt("+"));
  assert(!isnumfmt("1a"));
  assert(!isnumfmt("a1"));
  assert(!isnumfmt("12e"));
  assert(!isnumfmt("34E-"));
}
