/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 */

#include <stdio.h>

#define TABW 8
#define MAXL 1000

int line(char s[], int lim);
void entab(char s[]);

int main() {
	int len;
	char s[MAXL];

	printf("Note: for the sake of clarity, all tabs will be represented by '-'.\n");
	while (line(s, MAXL)) {
		entab(s);
		printf("%s", s);
	}
}

int line(char s[], int lim) {
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < lim - 1) {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}

void entab(char s[]) {
	int i;
	int j;
	int tp = -1; // position of current char in a tab range
	int sp = -1; // start position of tailed space in a tab range, -1 means no tailed space
	char c;
	for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
		s[j] = c;

		if (c == '\t') {
			tp = TABW - 1;
		} else {
			tp++;
		}

		if (c == ' ') {
			if (sp == -1) {
				sp = tp;
			}
		} else {
			sp = -1;
		}

		// reach a tab end
		if (tp == TABW - 1) {
			// with tailed space
			if (sp != -1) {
				int spacew = TABW - sp;
				j = j - spacew + 1;
				s[j] = '-';
				sp = -1;
			}
			tp = -1;
		}
	}
	s[j] = '\0';
}
