#pragma once

#include "../collections/vec.h"
#include <stddef.h>

typedef struct {
  vec_t *inner;
} dyn_string_t;

dyn_string_t *new_dyn_string();

dyn_string_t *new_dyn_string_from_lit(char *literal);

char dyn_string_get(size_t index);

size_t dyn_string_length(dyn_string_t *string);

void dyn_string_push_single(dyn_string_t *string, char ch);

void dyn_string_push_multiple(dyn_string_t *string, char *chars);
