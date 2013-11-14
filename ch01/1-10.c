#include <stdio.h>

int main() {
	char *s;
	int p = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			*(s + p++) = '\\';
			*(s + p++) = 't';
		} else if (c == '\n') {
			*(s + p++) = '\\';
			*(s + p++) = 'n';
		} else if (c == '\\') {
			*(s + p++) = '\\';
			*(s + p++) = '\\';
		} else {
			*(s + p++) = c;
		}
	}

	printf("\n%s", s);
}
