#include <stdio.h>

int bitlen(unsigned d);
unsigned rightrot(unsigned d, unsigned x);

int main() {
	printf("rightrot(11, 1) -> %u\n", rightrot(11, 1));
	printf("rightrot(1024, 14) -> %u\n", rightrot(1024, 14));
}

int bitlen(unsigned d) {
	int len = 0;
	for (; d; d >>= 1) {
		len++;
	}
	return len;
}

unsigned rightrot(unsigned d, unsigned x) {
	int len = bitlen(d);
	if (len) {
		x %= len;
		if (x) {
			unsigned right = d & ~(~0 << x);
			return right << len - x ^ d >> x;
		} else {
			return d;
		}
	} else {
		return 0;
	}
}
