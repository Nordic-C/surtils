#pragma once

#include <stddef.h>

// Uses vec-like behavior
typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} dyn_string_t;

dyn_string_t *new_dyn_string();

dyn_string_t *new_dyn_string_from_slice(char *literal);

char *dyn_string_get(const dyn_string_t *string, size_t index);

size_t dyn_string_length(const dyn_string_t *string);

void dyn_string_push_single_back(dyn_string_t *string, char ch);

void dyn_string_push_multiple_back(dyn_string_t *string, char *chars);

void dyn_string_push_single_front(dyn_string_t *string, char ch);

void dyn_string_push_multiple_front(dyn_string_t *string, char *chars);

char *dyn_string_as_slice(dyn_string_t *string);

void dyn_string_free(dyn_string_t *string);
