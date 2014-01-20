#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'o':
      ival = va_arg(ap, int);
      printf("%o", ival);
      break;
    case 'x':
    case 'X':
      ival = va_arg(ap, int);
      printf("%x", ival);
      break;
    case 'u':
      ival = va_arg(ap, int);
      printf("%u", ival);
      break;
    case 'c':
      ival = va_arg(ap, int);
      putchar(ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      printf("%s", va_arg(ap, char *));
      break;
    case '%':
      putchar('%');
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);
}

int main() {
  minprintf(
    "%%, %d, %o, %x, %u, %c, %s, %f\n",
    63, 63, 63, 63, 63, "abc", 63.0
  );
  return 0;
}
