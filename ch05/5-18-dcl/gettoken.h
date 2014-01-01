#ifndef _GETTOKEN_H_
#define _GETTOKEN_H_

#define MAXTOKEN 100

char tokenval[MAXTOKEN];

enum tokentypes {
  ILLEGAL,
  ID,
  KEYWORD,
  DIGITS
};

int gettoken(FILE *stream);
#endif
