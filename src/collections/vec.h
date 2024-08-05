#pragma once

#include <stddef.h>

#define VEC_FROM(vec_name, ...)                                                \
  void *values_##vec_name[] = {__VA_ARGS__};                                   \
  size_t count_##vec_name =                                                    \
      sizeof(values_##vec_name) / sizeof(values_##vec_name[0]);                \
  vec_t *vec_name = vec_new_with_size(count_##vec_name);                       \
  for (size_t i = 0; i < count_##vec_name; ++i) {                              \
    vec_push_back(vec_name, values_##vec_name[i]);                             \
  }

typedef struct {
  void **data;
  size_t length;
  size_t capacity;
} vec_t;

vec_t *vec_new();

vec_t *vec_new_with_size(size_t initial_size);

void vec_push_back(vec_t *vec, void *value);

void vec_push_front(vec_t *vect, void *value);

void *vec_remove(vec_t *vec, size_t index);

void *vec_pop(vec_t *vec);

void vec_set(vec_t *vec, size_t index, void *value);

void *vec_get(const vec_t *vec, size_t index);

void vec_free(vec_t *vec);

size_t vec_length(const vec_t *vec);
