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

int is_some(const Option *option);

int is_none(const Option *option);
