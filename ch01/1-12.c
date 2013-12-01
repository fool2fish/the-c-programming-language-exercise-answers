/*
 * Exercise 1-12
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>
#include <ctype.h>

int main() {
	int isIn = 0;
	char c;

	while((c = getchar()) != EOF) {
		if (isIn) {
			if (isspace(c)) {
				isIn = 0;
				putchar('\n');
			} else {
				putchar(c);
			}
		} else {
			if (!isspace(c)) {
				isIn = 1;
				putchar(c);
			}
		}
	}
}

