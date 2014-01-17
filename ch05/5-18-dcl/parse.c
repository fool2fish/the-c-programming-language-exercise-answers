#include <stdio.h>
#include <string.h>

#include "gettoken.h"
#include "parse.h"

char specifiers[MAXTOKEN];

static void declaration_specifiers();
static void declarator();
static int pointers();
static void direct_declarator();
static void direct_declarator_simple();
static void direct_declarator_arr_fn();
static void director_declarator_postfix();
static void printError(char *s);
static void expectNext(int c, char *s);


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
    int i = pointers();
    direct_declarator();
    while(--i >= 0) {
      printf("pointer to ");
    }
  } else {
    ungettoken();
    direct_declarator();
  }
}

static int pointers() {
  int i = 0;
  while (gettoken(), tokentype == '*') {
    i++;
  }
  ungettoken();
  return i;
}

static void direct_declarator() {
  direct_declarator_simple();
  direct_declarator_arr_fn();
}

static void direct_declarator_simple() {
  char s[] = "direct_declarator_simple";
  gettoken();
  if (tokentype == '(') {
    declarator();
    expectNext(')', s);
  } else if (tokentype == IDENTIFIER) {
    printf("%s: ", tokenval);
  } else {
    printError(s);
  }
}

static void direct_declarator_arr_fn() {
  gettoken();
  if (tokentype == '[' || tokentype == '(') {
    ungettoken();
    director_declarator_postfix();
    direct_declarator_arr_fn();
  } else {
    // epsilon
    ungettoken();
  }
}

static void director_declarator_postfix() {
  char s[] ="director_declarator_postfix";
  gettoken();
  if (tokentype == '[') {
    gettoken();
    if (tokentype == ']') {
      printf("array[] of ");
    } else if (tokentype == DIGITS) {
      printf("array[%s] of ", tokenval);
      expectNext(']', s);
    } else {
      printError(s);
    }
  } else if (tokentype == '(') {
    while (gettoken(), tokentype != ')') {
    }
    printf("function() returning ");
  } else {
    printError(s);
  }
}


static void printError(char *fn) {
  printf("\nParse error: %s\n  tokentype: %d,", fn, tokentype);
  if (ILLEGAL <= tokentype && tokentype <= DIGITS) {
    printf(" tokenval: %s,", tokenval);
  } else {
    printf(" tokenval: %c,", tokentype);
  }
  printf(" line: %d, col: %d\n", tokenline, tokencol);
}

static void expectNext(int c, char *fn) {
  gettoken();
  if (tokentype != c) {
    printError(fn);
    ungettoken();
  }
}






