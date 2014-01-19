#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "lookup.h"

int main() {
  assert(lookup("name") == NULL);

  install("name", "fool2fish");
  assert(strcmp(lookup("name")->value, "fool2fish") == 0);

  install("name", "chenyu");
    assert(strcmp(lookup("name")->value, "chenyu") == 0);

  undef("name");
  assert(lookup("name") == NULL);
}
