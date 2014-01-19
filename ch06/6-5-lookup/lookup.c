#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "lookup.h"

#define LEN 1000

static struct item *htable[LEN];

static char *strdup2(char *s) {
  char *p = (char *) malloc(strlen(s) + 1);
  if (p != NULL) {
    strcpy(p, s);
  }
  return p;
}

static unsigned hash(char *name) {
  unsigned val;
  for(val = 0; *name != '\0'; name++) {
    val = *name + 31 * val;
  }
  return val % LEN;
}

struct item *lookup(char *name) {
  unsigned hashval = hash(name);
  struct item *itemp;
  for (itemp = htable[hashval]; itemp != NULL; itemp = itemp->next) {
    if (strcmp(name, itemp->name) == 0) {
      return itemp;
    }
  }
  return NULL;
}

struct item *install(char *name, char *value) {
  struct item *itemp;
  if ((itemp = lookup(name)) == NULL) {
    itemp = (struct item *) malloc(sizeof(struct item));

    if (itemp == NULL) {
      return NULL;
    }

    if ((itemp->name = strdup2(name)) == NULL) {
      free((void *) itemp);
      return NULL;
    }

    unsigned hashval = hash(name);
    itemp->next = htable[hashval];
    htable[hashval] = itemp;
  } else {
    free((void *) itemp->value);
  }

  if ((itemp->value = strdup2(value)) == NULL) {
    return NULL;
  }

  return itemp;
}

void undef(char *name) {
  unsigned hashval = hash(name);
  struct item *itemp;
  struct item *previtemp;
  for (itemp = htable[hashval]; itemp != NULL; previtemp = itemp, itemp = itemp->next) {
    if (strcmp(name, itemp->name) == 0) {
      if (previtemp == NULL) {
        htable[hashval] = itemp->next;
      } else {
        previtemp->next = itemp->next;
      }
      free(itemp->name);
      free(itemp->value);
      free(itemp);
    }
  }
}






