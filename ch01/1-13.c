/*
 * Exercise 1-13.
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>
#include <ctype.h>

void updateCounts(int counts[], int size, int wordlen);
void painth(int counts[], int size);


int main() {
	int size = 10;
	int counts[size];
    int i;
	for(i = 0; i < size; counts[i++] = 0);

	int isIn = 0;
	int wordlen = 0;
	char c;
	while ((c = getchar()) != EOF) {
		if (isIn) {
			if (isspace(c)) {
				updateCounts(counts, size, wordlen);
				isIn = 0;
				wordlen = 0;
			} else {
				wordlen++;
			}
		} else {
			if (!isspace(c)) {
				isIn = 1;
				wordlen = 1;
			}
		}
	}
	if (wordlen > 0) updateCounts(counts, size, wordlen);

	painth(counts, size);
}


void updateCounts(int counts[], int size, int wordlen) {
	wordlen = wordlen < size ? wordlen : size;
	counts[wordlen - 1]++;
}

void painth(int counts[], int size) {
	int peak = 0;
	int i;
	for (i = 0; i < size; i++) {
		peak = peak > counts[i] ? peak : counts[i];
	}

	for (i = 0; i < size; i++) {
		int barlen = counts[i] * 20 / peak;
		char bar[barlen + 1];
		int j;
		for (j = 0; j < barlen; j++) {
			bar[j] = '+';
		}
		bar[j] = '\0';

		char *format = "  %2d: %s %d\n";
		if (i == size - 1) {
			format = ">=%2d: %s %d\n";
		}
		printf(format, i + 1, bar, counts[i]);
	}
}
