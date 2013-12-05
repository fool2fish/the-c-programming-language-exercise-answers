/*
 * Exercise 1-23
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 */

#include <stdio.h>

int main() {
	char prevc;
	char c;
	char nextc;
	while((c = getchar()) != EOF) {
		if (c == '"') {
			putchar(prevc = c); // print start double quotation mark
			while ((c = getchar()) != '"' || prevc == '\\') {
				putchar(prevc = c);
			}
			putchar(prevc = c); // print end double quotation mark

		} else if (c == '/') {
			nextc = getchar();
			if (nextc == '/') {
				while ((c = getchar()) != '\n');
				putchar('\n');
			} else if (nextc == '*') {
				prevc = getchar();
				while ((c = getchar()) != '/' || prevc != '*') {
					prevc = c;
				}
			} else {
				putchar(c);
				putchar(prevc = nextc);
			}

		} else {
			putchar(prevc = c);
		}
	}
}
