#include <assert.h>

int main(int argc, char *argv[]) {
  char c1 = getch();
  assert(c1 == '#');

  char c2 = getch();
  assert(c2 == 'i');

  assert(ungetch(c2));

  assert(!ungetch(c1));
}
