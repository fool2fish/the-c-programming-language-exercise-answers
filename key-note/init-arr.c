#include <stdio.h>

int global[2];
int global2[2] = {1};

int main() {
  int local[2];
  int local2[2] = {1};
  printf("global[0]: %d\n", global[0]);
  printf("global2: {%d, %d}\n", global2[0], global2[1]);
  printf("local[0]: %d\n", local[0]);
  printf("local2: {%d, %d}\n", local2[0], local2[1]);
}
