#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "gettoken.h"

static char *keywords[] = {
  "char", "int", "float", "double",
  "long", "short", "signed", "unsigned",
  "const", "struct", "void", ""
};

static int iskeyword(char *s) {
  int i;
  for (i = 0; strcmp(keywords[i], "") != 0; i++) {
    if (strcmp(s, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

static nextiseof;

int gettoken(FILE *stream) {
  int tokentype;
  int c;
  char *p = tokenval;

  if (nextiseof == EOF) {
    c = EOF;
  } else {
    while ((c = getc(stream)) == ' ' || c == '\t');
  }

  if (c == EOF) {
    tokentype = c;
    tokenval[0] = '\0';
  } else if (c == '(' || c == ')' || c == '[' || c == ']' || c == '*' || c == ',' || c == '\n') {
    tokentype = c;
    tokenval[0] = c;
    tokenval[1] = '\0';
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getc(stream));) {
      *p++ = c;
    }
    *p = '\0';
    if (iskeyword(tokenval)) {
      tokentype = KEYWORD;
    } else {
      tokentype = ID;
    }
    if (c == EOF) {
      nextiseof = EOF;
    } else {
      ungetc(c, stream);
    }
  } else if (isdigit(c)) {
    for (*p++ = c; isdigit(c = getc(stream));) {
      *p++ = c;
    }
    *p = '\0';
    tokentype = DIGITS;
    if (c == EOF) {
      nextiseof = EOF;
    } else {
      ungetc(c, stream);
    }
  } else {
    tokentype = ILLEGAL;
    tokenval[0] = c;
    tokenval[1] = '\0';
  }
  return tokentype;
}




