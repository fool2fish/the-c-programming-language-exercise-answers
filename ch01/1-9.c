#include <stdio.h>

int main() {
	char *s;
	int p = 0;
	char c;
	char prev;

	while((c = getchar()) != EOF) {
		if (c != ' ' || prev != ' ') {
			*(s + p++) = prev = c;
		}
	}

	printf("\n%s", s);
}
