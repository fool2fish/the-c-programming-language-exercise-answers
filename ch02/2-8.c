#include <stdio.h>

int bitlen(unsigned d);
unsigned rightrot(unsigned d, int x);

int main() {
	printf("rightrot(%u, %d) -> %u\n", 11, 1, rightrot(11, 1));
	printf("rightrot(%u, %d) -> %u\n", 1024, 14,rightrot(1024, 14));
}

int bitlen(unsigned d) {
	int len = 0;
	for (; d; d >>= 1) {
		len++;
	}
	return len;
}

unsigned rightrot(unsigned d, int x) {
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
