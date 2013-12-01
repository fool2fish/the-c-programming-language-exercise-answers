/*
 * Exercise 1-9
 * Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main() {
	char prev;
	char c;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || prev != ' ') {
			putchar(prev = c);
		}
	}


	/*
	char *s;
	int p = 0;
	char prev;
	char c;

	while((c = getchar()) != EOF) {
		if (c != ' ' || prev != ' ') {
			*(s + p++) = prev = c;
		}
	}

	printf("\n%s", s);
	*/
}
