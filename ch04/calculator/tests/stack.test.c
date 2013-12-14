#include <assert.h>
#include "../stack.h"

int main(int argc, char *argv[]) {
  double n1 = 12.34;
  double n2 = 56.2;
  double n3 = -78.9;

  push(n1);
  push(n2);
  assert(pop() == n2);
  push(n3);
  assert(pop() == n3);
  assert(pop() == n1);

  push(n1);
  push(n2);
  assert(gettop() == n2);
  swap();
  assert(pop() == n1);
  assert(pop() == n2);
}
