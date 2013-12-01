/*
 * Exercise 1-8
 * Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int space = 0;
int tab = 0;
int newline = 0;

int main() {
	int c;
	while((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			space++;
			break;
		case '\t':
			tab++;
			break;
		case '\n':
			newline++;
			break;
		default:
			break;
		}
	}
	printf("space:%d, tab:%d, newline:%d\n", space, tab, newline);
}

