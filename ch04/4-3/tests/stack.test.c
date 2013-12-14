#include <assert.h>
#include "../stack.h"

int main(int argc, char *argv[]) {
  double n1 = 12.34;
  double n2 = 56.0;
  double n3 = -78.9;
  double n;
  push(n1);
  push(n2);
  assert(pop() == n2);
  push(n3);
  assert(pop() == n3);
  assert(pop() == n1);
}
