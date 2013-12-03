/*
 * Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinex(char line[], int maxline);
void trimr(char line[]);

int main() {
	int len;
	char line[MAXLINE];
	while ((len = getlinex(line, MAXLINE)) > 0) {
		trimr(line);
		if (line[0] != '\n' && line[0] != '\0') {
			printf("%s", line);
		}
	}
}

int getlinex(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void trimr(char line[]) {
	char c;
	int i;
	int mark = -1;
	for (i = 0; (c = line[i]) != '\n' && c != '\0'; i++) {
		if (c == ' ' || c == '\t') {
			if (mark == -1) {
				mark = i;
			}
		} else {
			mark = -1;
		}
	}

	if (mark != -1 && i > 0) {
		if (line[i] == '\n') {
			line[mark++] = '\n';
		}
		line[mark] = '\0';
	}
}
