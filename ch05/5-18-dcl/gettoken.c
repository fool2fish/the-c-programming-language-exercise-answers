#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "gettoken.h"

static char *storage_class_specifier[] = {
  "auto", "register", "static", "extern", ""
};

static char *type_specifier[] = {
  "void", "char", "short", "int",
  "long", "float", "double",
  "signed", "unsigned", ""
};

static char *type_qualifier[] = {
  "const", "volatile", ""
};

static int isinlist(char *s, char *list[]) {
  int i;
  for (i = 0; strcmp(list[i], "") != 0; i++) {
    if (strcmp(s, list[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

static int gettokentype(char *s) {
  if (isinlist(s, storage_class_specifier)) {
    return STORAGE_CLASS_SPECIFIER;
  } else if (isinlist(s, type_specifier)) {
    return TYPE_SPECIFIER;
  } else if (isinlist(s, type_qualifier)) {
    return TYPE_QUALIFIER;
  } else {
    return IDENTIFIER;
  }
}


static int nextiseof = 0;
static int charline = 1;
static int charcol = 0;

static int getch(FILE *stream) {
  if (nextiseof) {
    return EOF;
  }

  int c = getc(stream);
  if (c == '\n') {
    charline++;
    charcol = 0;
  } else {
    charcol++;
  }
  return c;
}

static int ungetch(char c, FILE *stream) {
  if (c == EOF) {
    nextiseof = 1;
  } else {
    if (c == '\n') {
      charline--;
      charcol = 0;
    } else {
      charcol--;
    }
    return ungetc(c, stream);
  }
}


int gettoken(FILE *stream) {
  int tokentype;
  int c;
  char *p = tokenval;

  while ((c = getch(stream)) == ' ' || c == '\t');
  tokenline = charline;
  tokencol = charcol;

  if (c == EOF) {
    tokentype = c;
    tokenval[0] = '\0';
  } else if (c == '(' || c == ')' || c == '[' || c == ']' || c == '*' || c == ',' || c == '\n') {
    tokentype = c;
    tokenval[0] = c;
    tokenval[1] = '\0';
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch(stream));) {
      *p++ = c;
    }
    *p = '\0';
    tokentype = gettokentype(tokenval);
    ungetch(c, stream);
  } else if (isdigit(c)) {
    for (*p++ = c; isdigit(c = getch(stream));) {
      *p++ = c;
    }
    *p = '\0';
    tokentype = DIGITS;
    ungetch(c, stream);
  } else {
    tokentype = ILLEGAL;
    tokenval[0] = c;
    tokenval[1] = '\0';
  }
  return tokentype;
}




