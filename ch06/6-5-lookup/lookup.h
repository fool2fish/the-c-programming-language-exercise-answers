#ifndef _LOOCKUP_H_
#define _LOOCKUP_H_
struct item {
  char *name;
  char *value;
  struct item *next;
};

struct item *lookup(char *name);
struct item *install(char *name, char *value);
void undef(char *name);
#endif
