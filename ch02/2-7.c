/*
 * Exercise 2-7
 * Write a function invert(x,p,n) that
 * returns x with the n bits that begin at position p inverted
 * (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdio.h>

int bitlen(unsigned d);
unsigned invert(unsigned x, unsigned p, unsigned n);

int main() {
  printf("invert(5, 1, 1) -> %u\n", invert(5, 1, 1));
  printf("invert(5, 4, 1) -> %u\n", invert(5, 4, 1));
}

int bitlen(unsigned d) {
  int len = 0;
  for (; d; d >>= 1) {
    len++;
  }
  return len;
}

unsigned invert(unsigned x, unsigned p, unsigned n) {
  int len = bitlen(x);

  if (len < p + n) {
    printf("Error: illegal p<%u> or n<%u>.\n", p, n);
    return 0;

  } else {
    unsigned tail = len - p - n;
    unsigned right = x & ~(~0 << tail);
    x >>= tail;
    x ^= ~(~0 << n);
    x <<= tail;
    x |= right;
    return x;
  }
}
