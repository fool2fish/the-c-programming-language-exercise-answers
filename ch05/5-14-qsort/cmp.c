#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int charcmp(char c1, char c2, int caseSensitive);
static int getch(char *s, int i, int isdir);
static int basecmp(char *s1, char *s2, int caseSensitive, int isdir);

int numcmp(char *s1, char *s2) {
  float n1 = atof(s1);
  float n2 = atof(s2);
  if (n1 < n2) {
    return -1;
  } else if (n1 > n2) {
    return 1;
  } else {
    return 0;
  }
}

int strcmpi(char *s1, char *s2) {
  return basecmp(s1, s2, 0, 0);
}

int dircmp(char *s1, char *s2) {
  return basecmp(s1, s2, 1, 1);
}

int dircmpi(char *s1, char *s2) {
  return basecmp(s1, s2, 0, 1);
}


static int basecmp(char *s1, char *s2, int caseSensitive, int isdir) {
  int i = getch(s1, 0, isdir);
  int j = getch(s2, 0, isdir);
  int cmp;

  for (; i != -1 && j != -1; i = getch(s1, ++i, isdir), j = getch(s2, ++j, isdir)) {
    cmp = charcmp(s1[i], s2[j], caseSensitive);
    if (cmp != 0) {
      return cmp;
    }
  }

  if (i == -1 && j == -1) {
    return 0;
  } else if (i == -1) {
    return -1;
  } else {
    return 1;
  }
}


static int getch(char *s, int i, int isdir) {
  char c;
  do {
    c = *(s + i++);
  } while (isdir && !isalnum(c) && c != ' ' && c != '\0');

  if (c == '\0') {
    return -1;
  } else {
    return --i;
  }
}


static int charcmp(char c1, char c2, int caseSensitive) {
  if (!caseSensitive && isalpha(c1) && isalpha(c2)) {
    c1 = tolower(c1);
    c2 = tolower(c2);
  }

  if (c1 < c2) {
    return -1;
  } else if (c1 > c2) {
    return 1;
  } else {
    return 0;
  }
}

