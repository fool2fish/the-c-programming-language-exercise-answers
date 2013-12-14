#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "getop.h"
#include "isnumfmt.h"
#include "stack.h"
#include "getline2.h"

#define MAX 100

int main(int argc, char *argv[]) {
  char line[MAX];
  char t[MAX];
  double tmp;

  while(getline2(line)) {
    printf("get line: %s\n", line);

    int start = 0;
    while ((start = getop(line, start, t)) != -1) {
      printf("getop: %s\n", t);
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
        tmp = pop();
        if (tmp != 0) {
          push(pop() / tmp);
        } else {
          pop();
          push(0.0);
          printf("Error: divisor is 0\n");
        }
      } else if (!strcmp(t, "%")) {
        tmp = pop();
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

    printf("result: %g\n", gettop());
    clearstack();
  }



  return 0;
}

