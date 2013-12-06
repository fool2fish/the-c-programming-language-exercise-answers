/*
 * Exercise 2-6
 * Write a function setbits(x,p,n,y)
 * that returns x with the n bits that begin at position p
 * set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 */

#include <stdio.h>

int bitlen(unsigned d);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() {
  printf("setbits(11, 1, 2, 6) -> %u\n", setbits(11, 1, 2, 6));
  printf("setbits(11, 3, 2, 6) -> %u\n", setbits(11, 3, 2, 6));
}

int bitlen(unsigned d) {
  int len = 0;
  for (; d; d >>= 1) {
    len++;
  }
  return len;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
  unsigned lenx = bitlen(x);
  unsigned leny = bitlen(y);

  if (lenx < p + n || leny < n) {
    printf("Error: illegal p<%u> or n<%u>.\n", p, n);
    return 0;

  } else {
    unsigned tail = lenx - p - n;
    unsigned right = x & ~(~0 << tail);
    unsigned replacement = y & ~(~0 << n);
    x >>= lenx - p;
    x <<= n;
    x |= replacement;
    x <<= tail;
    x |= right;
    return x;
  }
}
