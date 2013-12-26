#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void tail(int n);
static int getline2(char *s, int len);
static void strcpy2(char *from, char *to);

int main(int argc, char *argv[]) {
  int n  = 10;
  while (--argc > 0) {
    char *arg = *++argv;
    if (*arg == '-') {
      n = atoi(++arg);
    }
  }
  tail(n);
}

void tail(int n) {
  int count = 0;
  char *lines[n];

  char s[MAXLINE];
  int w;
  char *p;

  while (w = getline2(s, MAXLINE)) {
    p = malloc(w);

    if (p == NULL) {
      printf("Memory allocation error.");
      return;

    } else {
      strcpy(p, s);
      if (count >= n) {
        free(lines[count % n]);
      }
      lines[count % n] = p;
      count++;
    }
  }

  int start = 0;
  int end = count;
  if (count >= n) {
    start = count;
    end = count + n;
  }
  printf("---->\n");
  for (; start < end; start++) {
    printf("%s", lines[start % n]);
    free(lines[start % n]);
  }
  printf("<----\n");
}

static int getline2(char *s, int len) {
  static char c;
  if (c == EOF) {
    return 0;
  }

  int i = 0;
  while ((c = getchar()) != '\n' && c != EOF && i < len - 1) {
    *(s + i++) = c;
  }
  if (c == '\n') {
    *(s + i++) = c;
  }
  *(s + i) = '\0';
  return i;
}

