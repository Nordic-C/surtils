#pragma once

#include <stddef.h>

typedef struct vec Vec;

Vec *new_vec();

void vec_push(Vec *vec, void *value);

void *vec_remove(Vec *vec, size_t index);

void *vec_pop(Vec *vec);

void vec_set(Vec *vec, size_t index, void *value);

void *vec_get(const Vec *vec, size_t index);

void vec_free(Vec *vec);

size_t vec_length(const Vec *vec);
