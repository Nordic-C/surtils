#include "option.h"
#include <stdio.h>
#include <stdlib.h>

Option some(void *val) { return (Option){.type = SOME, .option = val}; }

Option none() { return (Option){.type = NONE, .option = NULL}; }

void *unwrap(Option *option) {
  if (option->type != SOME) {
    fprintf(stderr, "Attempt to unwrap an Option even though it is NONE\n");
    exit(1);
  }
  return option->option;
}

void *expect(Option *option, char *msg) {
  if (option->type != SOME) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
  }
  return option->option;
}

int is_some(Option *option) { return option->type == SOME; }

int is_none(Option *option) { return !is_some(option); }
