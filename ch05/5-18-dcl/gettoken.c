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
    if (iskeyword(tokenval)) {
      tokentype = KEYWORD;
    } else {
      tokentype = ID;
    }
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




