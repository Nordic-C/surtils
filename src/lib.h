#pragma once

#include "generics/vec.h"

DEFINE_VEC_EXPORTS(int);

// Type that should only be NULL
typedef void *null_t;

vec_gt(int) *get_s();
