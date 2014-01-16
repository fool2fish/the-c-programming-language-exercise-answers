#ifndef _GETTOKEN_H_
#define _GETTOKEN_H_

#define MAXTOKEN 100

FILE *stream;

int tokentype;
char tokenval[MAXTOKEN];
int tokenline;
int tokencol;

enum tokentypes {
  ILLEGAL,
  IDENTIFIER,
  STORAGE_CLASS_SPECIFIER,
  TYPE_SPECIFIER,
  TYPE_QUALIFIER,
  DIGITS
};

int gettoken();
int ungettoken();
#endif
