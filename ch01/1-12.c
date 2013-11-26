#include <stdio.h>

int isBlank(char c) {
	return c == ' ' || c == '\n' || c == '\t';
}

int main() {
	int isIn = 0;
	char c;

	while((c = getchar()) != EOF) {
		if (isIn) {
			if (isBlank(c)) {
				isIn = 0;
				putchar('\n');
			} else {
				putchar(c);
			}
		} else {
			if (!isBlank(c)) {
				isIn = 1;
				putchar(c);
			}
		}
	}
}

