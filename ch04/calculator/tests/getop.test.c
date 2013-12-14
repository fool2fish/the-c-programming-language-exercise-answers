#include <assert.h>
#include <string.h>
#include "../getop.h"

int main(int argc, char *argv[]) {
  char s[100];
  
  assert(getop(s));
  assert(!strcmp(s,"worda"));

  assert(getop(s));
  assert(!strcmp(s,"wordb"));
  
  assert(getop(s));
  assert(!strcmp(s,"wordc"));
  
  assert(!getop(s));
}
