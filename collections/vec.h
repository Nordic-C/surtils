//
// Created by thepigcat on 2/26/24.
//

#pragma once

#include <stdlib.h>

typedef struct vec Vec;

Vec *newVec();

void vec_push(Vec *vec, int value);

void vec_remove(Vec *vec, size_t index);

void vec_pop(Vec *vec);

int *vec_get(const Vec *vec, size_t index);

void vec_free(Vec *vec);

void vec_print(const Vec *vec);

size_t vec_length(const Vec *vec);