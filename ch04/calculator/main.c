#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
      swap();
      push(pop() - pop());
    } else if (!strcmp(s, "/")) {
      tmp = pop();
      if (tmp != 0) {
        push(pop() / tmp);
      } else {
        pop();
        push(0.0);
        printf("Error: divisor is 0\n");
      }
    } else if (!strcmp(s, "%")) {
      tmp = pop();
      if (tmp != 0) {
        push((int) pop() % (int) tmp);
      } else {
        pop();
        push(0.0);
        printf("Error: divisor is 0\n");
      }

    } else if (!strcmp(s, "pow")) {
      double tmp = pop();
      push(pow(pop(), tmp));

    } else if (!strcmp(s, "exp")) {
      push(exp(pop()));

    } else if (!strcmp(s, "sin")) {
      push(sin(pop()));

    } else {
      printf("Error: unknown token %s\n", s);
    }
  }
  printf("result: %g\n", gettop());
  return 0;
}

