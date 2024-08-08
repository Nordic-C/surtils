#include "../lib.h"

#pragma once

typedef enum {
  SOME,
  NONE,
} OptionType;

typedef struct {
  OptionType type;
  void *option;
} Option;

Option some(void *val);

Option none();

void *unwrap(Option *option);

void *expect(Option *option, char *msg);

int is_some(Option *option);

int is_none(Option *option);
