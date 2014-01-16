#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "gettoken.h"

int main() {
  /*
  int tokentype;
  while ((tokentype = gettoken()) != EOF) {
    printf("%s (line:%d, col:%d)\n", tokenval, tokenline, tokencol);
  }
  */
  stream = stdin;

  assert(gettoken() == TYPE_QUALIFIER);
  assert(strcmp(tokenval, "const") == 0);

  ungettoken();
  assert(gettoken() == TYPE_QUALIFIER);
  assert(strcmp(tokenval, "const") == 0);

  assert(gettoken() == TYPE_SPECIFIER);
  assert(strcmp(tokenval, "char") == 0);

  assert(gettoken() == '*');
  assert(gettoken() == '(');
  assert(gettoken() == '*');

  assert(gettoken() == IDENTIFIER);
  assert(strcmp(tokenval, "foo") == 0);

  assert(gettoken() == '(');

  assert(gettoken() == TYPE_SPECIFIER);
  assert(strcmp(tokenval, "void") == 0);

  assert(gettoken() == '*');

  assert(gettoken() == IDENTIFIER);
  assert(strcmp(tokenval, "p") == 0);

  assert(gettoken() == ',');

  assert(gettoken() == TYPE_SPECIFIER);
  assert(strcmp(tokenval, "int") == 0);

  assert(gettoken() == IDENTIFIER);
  assert(strcmp(tokenval, "param") == 0);

  assert(gettoken() == ')');
  assert(gettoken() == ')');

  assert(gettoken() == '[');

  assert(gettoken() == DIGITS);
  assert(strcmp(tokenval, "100") == 0);

  assert(gettoken() == ']');

  return 0;
}
