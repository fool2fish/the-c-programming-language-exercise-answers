#define MAXLINE 100
#define TABING  8

int tabpos(int pos, int *tab) {
  return tab[pos] || pos >= MAXLINE;
}
