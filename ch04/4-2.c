/* Exercise 4-2
 * Extend atof to handle scientific notation of the form 
 *    123.45e-6
 * where a floating-point number may be followed by e or E 
 * and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
  printf("0 -> %e\n", atof("0"));
  printf("123.456 -> %g\n", atof("123.456"));
  printf("-67.890 -> %g\n", atof("-67.89"));
  printf("1.23e+20 -> %g\n", atof("1.23e+20"));
  printf("-4.56E-6 -> %g\n", atof("-4.56E-6"));
}

double atof(char s[]) {
  double val;
  double power;
  int i;
  int sign;
  
  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '-' || s[i] == '+') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if(s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++, power *= 10.0) {
    val = 10 * val + (s[i] - '0');
  }

  val = sign * val / power;

  if(s[i] == 'e' || s[i] == 'E') {
    i++;
    int expsign = 1;
    int exp;
    
    if (s[i] == '-') {
      expsign = -1;
    }
    
    if(s[i] == '-' || s[i] == '+') {
      i++;
    }

    for (exp = 0; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
    }
  
    exp = exp * expsign;

    if (exp > 0) {
      while (exp-- > 0) {
        val = 10.0 * val;
      }
    } else if (exp < 0) {
      while (exp++ < 0) {
        val = val / 10.0;
      }
    }
  }

  return val;
}






