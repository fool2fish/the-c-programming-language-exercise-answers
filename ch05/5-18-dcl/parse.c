#include <stdio.h>
#include <string.h>

#include "gettoken.h"
#include "parse.h"

char specifiers[MAXTOKEN];

static void declaration_specifiers();
static void declarator();
static void pointers();
static void direct_declarator();

void parse() {
  declaration_specifiers();
  declarator();
  printf("%s\n", specifiers);
}

static void declaration_specifiers() {
  while (gettoken(), STORAGE_CLASS_SPECIFIER <= tokentype && tokentype <= TYPE_QUALIFIER) {
    strcat(specifiers, tokenval);
    strcat(specifiers, " ");
  }
  ungettoken();
}

static void declarator() {
  gettoken();
  if (tokentype == '*') {
    ungettoken();
    pointers();
    direct_declarator();
  } else {
    ungettoken();
    direct_declarator();
  }
}

static void pointers() {
  while (gettoken(), tokentype == '*') {
    printf("pointer to ");
  }
  ungettoken();
}

static void direct_declarator() {

}
