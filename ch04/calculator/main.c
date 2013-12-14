#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "getop.h"
#include "isnumfmt.h"
#include "stack.h"

#define MAX 100

int main(int argc, char *argv[]) {
  char s[MAX];
  double tmp;

  while (getop(s)) {
    if (isnumfmt(s)) {
      push(atof(s));
    } else if (!strcmp(s, "+")) {
      push(pop() + pop());
    } else if (!strcmp(s, "*")) {
      push(pop() * pop());
    } else if (!strcmp(s, "-")) {
      tmp = pop();
      push(pop() - tmp);
    } else if (!strcmp(s, "/")) {
      tmp = pop();
      if (tmp != 0) {
        push(pop() / tmp);
      } else {
        printf("Error: divisor is 0\n");
      }
    } else if (!strcmp(s, "%")) {
      tmp = pop();
      if (tmp != 0) {
        push((int) pop() % (int) tmp);
      } else {
        printf("Error: divisor is 0\n");
      }
    } else {
      printf("Error: unknown token %s\n", s);
    }
  }
  printf("result: %g\n", pop());
  return 0;
}

