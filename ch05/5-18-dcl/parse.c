#include <stdio.h>
#include <string.h>

#include "gettoken.h"
#include "parse.h"

char specifiers[MAXTOKEN];

void declaration_specifiers();
void declarator();

void parse() {
  declaration_specifiers();
  declarator();
  printf("%s\n", specifiers);
}

void declaration_specifiers() {
  while (gettoken(), 2 <= tokentype && tokentype <= 4) {
    strcat(specifiers, tokenval);
    strcat(specifiers, " ");
  }
  ungettoken();
}

void declarator() {

}
