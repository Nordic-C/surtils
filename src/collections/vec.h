#pragma once

#include <stddef.h>

#define VEC_FROM(vec_name, ...)                                                \
  void *values[] = {__VA_ARGS__};                                              \
  size_t count = sizeof(values) / sizeof(values[0]);                           \
  vec_t *vec_name = new_vec_with_size(count);                                                 \
  for (size_t i = 0; i < count; ++i) {                                         \
    vec_push(vec_name, values[i]);                                             \
  }

typedef struct {
  void **data;
  size_t length;
  size_t capacity;
} vec_t;

vec_t *new_vec();

vec_t *new_vec_with_size(size_t initial_size);

void vec_push(vec_t *vec, void *value);

void *vec_remove(vec_t *vec, size_t index);

void *vec_pop(vec_t *vec);

void vec_set(vec_t *vec, size_t index, void *value);

void *vec_get(const vec_t *vec, size_t index);

void vec_free(vec_t *vec);

size_t vec_length(const vec_t *vec);
