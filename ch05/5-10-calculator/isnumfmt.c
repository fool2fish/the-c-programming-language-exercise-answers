#include <ctype.h>

/*
 * Check if a string in number format.
 * [+|-]?\d*(\.\d*)?([e|E][+|-]?\d+)?
 */
int isnumfmt(char s[]) {
  int i = 0, c;
  
  if ((c = s[i]) == '+' || c == '-') {
    i++;
  }

  if (s[i] == '\0') {
    return 0;
  }

  for (; isdigit(c = s[i]); i++);

  if (c == '.') {
    i++;
  }
  
  for (; isdigit(c = s[i]); i++);

  if (c == 'e' || c == 'E') {
    int c2 = s[i + 1];
    int c3 = s[i + 2];
    if ((c2 == '+' || c2 == '-') && isdigit(c3)) {
      i += 2;
    } else if (isdigit(c2)) {
      i++;
    }
  }

  for (; isdigit(c = s[i]); i++);

  return c == '\0';
}

