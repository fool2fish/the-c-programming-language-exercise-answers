#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "cmp.h"

int main(int argc, char *argv[]) {

  assert(numcmp("abc", "9ab") == -1);
  assert(numcmp("9ab", "10c") == -1);
  assert(numcmp("10c", "10d") == 0);

  assert(strcmpi("abc", "ABC") == 0);
  assert(strcmpi("ab", "A") == 1);
  assert(strcmpi("AB", "c") == -1);

  char s1[] = {'\t', 'a', ' ', '\0'};
  char s2[] = {'a', ' ', '\t', '\0'};
  char s3[] = {'A', '\t', ' ', '\0'};

  assert(dircmp(s1, s2) == 0);
  assert(dircmp(s3, s2) == -1);
  assert(dircmp(s1, s3) == 1);

  assert(dircmpi(s1, s3) == 0);
  assert(dircmpi(s2, s3) == 0);
}
