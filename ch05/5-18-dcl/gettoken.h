#ifndef _GETTOKEN_H_
#define _GETTOKEN_H_

#define MAXTOKEN 100

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

int gettoken(FILE *stream);
#endif
