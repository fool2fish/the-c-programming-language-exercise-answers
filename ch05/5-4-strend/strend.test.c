#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "strend.h"

int main(int argc, char *argv[]) {
  assert(strend("abcde", "cde"));
  assert(!strend("abcde", "cdef"));
}
