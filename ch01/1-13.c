/*
 * Exercise 1-13.
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>
#include <ctype.h>

void updatecounts(int counts[], int size, int wordlen);
int getpeak(int counts[], int size);
void painth(int counts[], int size);
void paintv(int counts[], int size);


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
				updatecounts(counts, size, wordlen);
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
	if (wordlen > 0) updatecounts(counts, size, wordlen);

	painth(counts, size);

	paintv(counts, size);
}


void updatecounts(int counts[], int size, int wordlen) {
	wordlen = wordlen < size ? wordlen : size;
	counts[wordlen - 1]++;
}

int getpeak(int counts[], int size) {
	int peak = 0;
	int i;
	for (i = 0; i < size; i++) {
		peak = peak > counts[i] ? peak : counts[i];
	}
	return peak;
}

void painth(int counts[], int size) {
	printf("\nHorizontal histogram:\n\n");
	int peak = getpeak(counts, size);

	int i;
	for (i = 0; i < size; i++) {
		int barsize = counts[i] * 20 / peak + 1;
		char bar[barsize];
		int j;
		for (j = 0; j < barsize - 1; j++) {
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

void paintv(int counts[], int size) {
	printf("\nVertical histogram:\n\n");
	int peak = getpeak(counts, size);
	int i, j, h = 20;

	int bars[size];
	for (i = 0; i < size; i++) {
		bars[i] = counts[i] * h / peak;
	}

	for (i = 0; i <= h; i++) {
		for(j = 0; j < size; j++) {
			if (h - i == bars[j]) {
				printf("%-5d", counts[j]);
			} else if (h - i < bars[j]) {
				printf("%-5c", '+');
			} else {
				printf("%-5c", ' ');
			}
		}
		printf("\n");
	}

	for (i = 0; i < size; i++) {
		printf("=====");
	}
	printf("\n");

	for (i = 0; i < size; i++) {
		char *format = "%-5d";
		if (i == size - 1) {
			format = ">=%-5d";
		}
		printf(format, i + 1);
	}
	printf("\n");
}
