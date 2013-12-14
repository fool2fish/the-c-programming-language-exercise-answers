#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "../getline2.h"

int main(int argc, char *argv[]) {
  char s[1000];

  getline2(s);
  assert(!strcmp(s, "line1\n"));

  getline2(s);
  assert(!strcmp(s, "\n"));

  getline2(s);
  assert(!strcmp(s, "line3"));

  assert(!getline2(s));
}
