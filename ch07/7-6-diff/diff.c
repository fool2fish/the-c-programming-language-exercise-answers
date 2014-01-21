#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1000

static void rmlb(char *p) {
  int len = strlen(p);
  if (len > 1 && p[len - 1] == '\n') {
    p[len - 1] = '\0';
  }
}

int diff(char *name1, char *name2) {
  FILE *f1, *f2;
  if ((f1 = fopen(name1, "r")) == NULL || (f2 = fopen(name2, "r")) == NULL) {
    fprintf(stderr, "Error: cannot open file: %s\n", f1 == NULL ? name1 : name2);
    exit(1);
  }

  char s1[LEN], s2[LEN], *p1, *p2;
  int line = 0;
  while (++line, p1 = fgets(s1, LEN, f1), p2 = fgets(s2, LEN, f2), p1 != NULL && p2 != NULL) {
    rmlb(s1);
    rmlb(s2);
    if (strcmp(s1, s2) != 0) {
      printf("First different at line:%d\n", line);
      printf("%s: %s\n%s: %s\n", name1, s1, name2, s2);
      return line;
    }
  }

  if (p1 != NULL || p2 != NULL) {
    printf("File: %s reached EOF or encounters an error.\n", f1 == NULL ? name1 : name2);
    return line;
  }

  printf("No diff.");
  return 0;
}

int main() {
  diff("a.txt", "b.txt");
}
