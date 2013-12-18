#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

static char allocbuf2[ALLOCSIZE];
static int allocp2 = 0;

char *alloc2(int n) {
  if (ALLOCSIZE - allocp2 >= n) {
    allocp2 += n;
    return &allocbuf2[allocp2 - n];
  } else {
    return 0;
  }
}
