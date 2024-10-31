#pragma once

#include "shared.h"

#define MAP(k_type, v_type) __map_##k_type##_##v_type##_t

#define map_new(k_type, v_type) __map_##k_type##_##v_type##_new()

#define map_insert(map, key, value)

#define DEFINE_MAP(k_type, v_type)                                             \
  MAP(k_type, v_type) __map_##k_type##_##v_type##_new() {                      \
    MAP(k_type, v_type) map;                                                   \
    map.keys = malloc(sizeof(k_type));                                         \
    map.values = malloc(sizeof(v_type));                                       \
    map.length = 0;                                                            \
    map.capacity = 0;                                                          \
    return map;                                                                \
  }

#define DEFINE_MAP_EXPORTS(k_type, v_type)                                     \
  typedef struct {                                                             \
    k_type *keys;                                                              \
    v_type *values;                                                            \
    ssize_t length;                                                            \
    ssize_t capacity;                                                          \
    CMP_FN_T(cmp_fn, k_type);                                                  \
  } __map_##k_type##_##v_type##_t;                                             \
                                                                               \
  MAP(k_type, v_type) __map_##k_type##_##v_type##_new();\
\
  _Bool __map_##k_type##_##v_type##_insert(MAP(k_type, v_type) *map, k_type key, v_type value);\
