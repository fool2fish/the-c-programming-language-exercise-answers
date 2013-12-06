/*
 * Exercise 2-9
 * In a two's complement number system,
 * x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main() {
	printf("%d's bit count is: %d\n", 1023, bitcount(1023));
	printf("%d's bit count is: %d\n", 1024, bitcount(1024));
}

int bitcount(unsigned x) {
	int len = 0;
	for (; x; x &= x - 1) {
		len++;
	}
	return len;
}
