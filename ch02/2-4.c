/*
 * Exercise 2-4
 * Write an alternative version of squeeze(s1,s2) 
 * that deletes each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

void getfailures(char s[], int failures[]);
int indexof(char s[], char subs[], int failures[]);
void squeeze(char s1[], char s2[]);

int main() {
  char s1[] = "abaaabcdaaabefaaabg";
  char s2[] = "aaab";
  squeeze(s1, s2);
  printf("%s\n", s1);
}

void getfailures(char s[], int failures[]) {
  failures[0] = 0;
  int i;
  int j = 0;

  for (i = 1; i < strlen(s); i++) {
    while (j > 0 && s[j] != s[i]) {
      j = failures[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    failures[i] = j;
  }
}

// Use KMP algorithm
int indexof(char s[], char subs[], int failures[]) {
  static int start = 0;
  int i;
  int j = 0;

  for (i = start; i < strlen(s); i++) {
    while (j > 0 && s[i] != subs[j]) {
      j = failures[j - 1];
    }
    if (s[i] == subs[j]) {
      j++;
    }
    if (j == strlen(subs)) {
      start = i + 1;
      return i - j + 1;
    }
  }
  start = 0;
  return -1;
}

void squeeze(char s1[], char s2[]) {
  int len = strlen(s2);
  int failures[len];
  getfailures(s2, failures);
  int previ = 0;
  int i;
  int j = 0;
  while ((i = indexof(s1, s2, failures)) != -1) {
    int k;
    for (k = previ ? previ + len : previ ; k < i; k++) {
      s1[j++] = s1[k];
    }
    previ = i;
  }
  s1[j] = '\0';
}
