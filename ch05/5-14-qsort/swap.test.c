#include <assert.h>
#include <string.h>

#include "swap.h"

int main(int argc, char *argv[]) {
  char *s1 = "one";
  char *s2 = "two";
  char *s3 = "three";
  char *s[] = {s1, s2, s3};

  swap(s, 0, 2);

  assert(!strcmp(s[0], "three"));
  assert(!strcmp(s[2], "one"));
}
