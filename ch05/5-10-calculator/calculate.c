#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "isnumfmt.h"
#include "stack.h"

double calculate(char *tokens[], int len) {
  char *t;
  int i;
  for (i = 0; i < len; i++) {
    t = tokens[i];
    if (isnumfmt(t)) {
      push(atof(t));
    } else if (!strcmp(t, "+")) {
      push(pop() + pop());
    } else if (!strcmp(t, "*")) {
      push(pop() * pop());
    } else if (!strcmp(t, "-")) {
      swap();
      push(pop() - pop());
    } else if (!strcmp(t, "/")) {
      double tmp = pop();
      if (tmp != 0) {
        push(pop() / tmp);
      } else {
        pop();
        push(0.0);
        printf("Error: divisor is 0\n");
      }
    } else if (!strcmp(t, "%")) {
      double tmp = pop();
      if (tmp != 0) {
        push((int) pop() % (int) tmp);
      } else {
        pop();
        push(0.0);
        printf("Error: divisor is 0\n");
      }

    } else if (!strcmp(t, "pow")) {
      double tmp = pop();
      push(pow(pop(), tmp));

    } else if (!strcmp(t, "exp")) {
      push(exp(pop()));

    } else if (!strcmp(t, "sin")) {
      push(sin(pop()));

    } else {
      printf("Error: unknown token %s\n", t);
    }
  }

  double rt = gettop();
  clearstack();
  return rt;
}
