#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "gettoken.h"

int main() {
  /*
  int tokentype;
  while ((tokentype = gettoken(stdin)) != EOF) {
    printf("%s (line:%d, col:%d)\n", tokenval, tokenline, tokencol);
  }
  */

  assert(gettoken(stdin) == KEYWORD);
  assert(strcmp(tokenval, "const") == 0);

  assert(gettoken(stdin) == KEYWORD);
  assert(strcmp(tokenval, "char") == 0);

  assert(gettoken(stdin) == '*');
  assert(gettoken(stdin) == '(');
  assert(gettoken(stdin) == '*');

  assert(gettoken(stdin) == ID);
  assert(strcmp(tokenval, "foo") == 0);

  assert(gettoken(stdin) == '(');

  assert(gettoken(stdin) == KEYWORD);
  assert(strcmp(tokenval, "void") == 0);

  assert(gettoken(stdin) == '*');

  assert(gettoken(stdin) == ID);
  assert(strcmp(tokenval, "p") == 0);

  assert(gettoken(stdin) == ',');

  assert(gettoken(stdin) == KEYWORD);
  assert(strcmp(tokenval, "int") == 0);

  assert(gettoken(stdin) == ID);
  assert(strcmp(tokenval, "param") == 0);

  assert(gettoken(stdin) == ')');
  assert(gettoken(stdin) == ')');

  assert(gettoken(stdin) == '[');

  assert(gettoken(stdin) == DIGITS);
  assert(strcmp(tokenval, "100") == 0);

  assert(gettoken(stdin) == ']');

  return 0;
}
