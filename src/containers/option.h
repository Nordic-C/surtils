#pragma once

typedef enum {
  SOME,
  NONE,
} OptionType;

typedef union {
  void *some;
  void *none;
} InnerOption;

typedef struct {
  OptionType type;
  InnerOption option;
} Option;

Option some(void *val);

Option none();

void *unwrap(Option *option);

void *expect(Option *option, char *msg);

int is_some(Option *option);

int is_none(Option *option);
