#pragma once

#include <stdlib.h>

typedef struct _ Vec;

Vec *newVec();

void vec_push(Vec *vec, int value);

void vec_remove(Vec *vec, size_t index);

void vec_pop(Vec *vec);

int *vec_get(const Vec *vec, size_t index);

void vec_free(Vec *vec);

void vec_print(const Vec *vec);

size_t vec_length(const Vec *vec);