/*
 * Exercise 1-10
 * Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

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
