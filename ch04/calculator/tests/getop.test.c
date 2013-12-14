#include <assert.h>
#include <string.h>
#include "../getop.h"

int main(int argc, char *argv[]) {
  char *s = "12.3 4.5 +\n";
  char t[100];
  int i = 0;

  assert(i = getop(s, i, t));
  assert(!strcmp(t,"12.3"));

  assert(i = getop(s, i, t));
  assert(!strcmp(t,"4.5"));
  
  assert(i = getop(s, i, t));
  assert(!strcmp(t,"+"));
  
  assert(getop(s, i, t) == -1);

  s = " a b c \n";
  i = 0;

  assert(i = getop(s, i, t));
  assert(!strcmp(t,"a"));

  assert(i = getop(s, i, t));
  assert(!strcmp(t,"b"));

  assert(i = getop(s, i, t));
  assert(!strcmp(t,"c"));

  assert(getop(s, i, t) == -1);
}
