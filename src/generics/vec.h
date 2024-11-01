#pragma once

#include <stdio.h>
#include <stdlib.h>

#define VEC(type) vec_##type##_t

#define vec_new(type) vec_##type##_new()

#define vec_new_sized(type, size) vec_##type##_new_with_size(size)

#define vec_get(type, vec, index) vec_##type##_get(vec, index)

#define vec_push_back(type, vec, elem) vec_##type##_push_back(vec, elem)

#define vec_push_front(type, vec, elem) vec_##type##_push_front(vec, elem)

#define vec_free(type, vec) vec_##type##_free(vec)

// clang-format off
#define DEFINE_VEC(type) \
                                                                               \
  VEC(type) vec_##type##_new() {                                           \
    /**/                                                                       \
    VEC(type) vec;          \
    vec.data = (type *)malloc(sizeof(type ));                                 \
    vec.capacity = 1;                                                         \
    vec.length = 0;                                                           \
    return vec;                                                                \
  }                                                                            \
                                                                               \
  VEC(type) vec_##type##_new_with_size(size_t initial_size) {              \
    VEC(type) vec;          \
    vec.data = (type *)malloc(sizeof(type) * initial_size);                  \
    vec.capacity = initial_size;                                              \
    vec.length = 0;                                                           \
    return vec;                                                                \
  }                                                                            \
                                                                               \
  static void vec_##type##_resize(VEC(type) *vec, size_t capacity) {        \
    type *items = (type *)realloc(vec->data, sizeof(type ) * capacity);        \
    if (items) {                                                               \
      vec->data = items;                                                       \
      vec->capacity = capacity;                                                \
    }                                                                          \
  }                                                                            \
                                                                               \
  /* This function assumes that there is enough room to push the elements      \
   * back.                                                                     \
   */                                                                          \
  static void vec_##type##_push_elements_back(VEC(type) *vec,               \
                                            size_t offset) {                   \
    for (size_t i = vec->length; i > 0; i--) {                                 \
      type elem = vec->data[i - 1];                                            \
      vec->data[i - 1 + offset] = elem;                                        \
    }                                                                          \
  }                                                                            \
                                                                               \
  /* Function to free the memory used by the vector */                         \
  void vec_##type##_free(VEC(type) * vec) {                                 \
    free(vec->data);                                                           \
    free(vec);                                                                 \
  }                                                                            \
                                                                               \
  /* Function to add an item to the vector */                                  \
  void vec_##type##_push_back(VEC(type) * vec, type item) {                 \
    if (vec->length == vec->capacity) {                                        \
      vec_##type##_resize(vec, vec->capacity * 2);                             \
    }                                                                          \
    vec->data[vec->length++] = item;                                           \
  }                                                                            \
  /* FIXME: Might leak */                                                      \
  void vec_##type##_push_front(VEC(type) *vec, type item) {                 \
    if (vec->length == vec->capacity) {                                        \
      vec_##type##_resize(vec, vec->capacity * 2);                             \
    }                                                                          \
    vec_##type##_push_elements_back(vec, 1);                                   \
    vec->data[0] = item;                                                       \
    vec->length++;                                                             \
  }                                                                            \
                                                                               \
  /* Function to get an item from the vector at a specific index */            \
  type vec_##type##_get(const VEC(type) *vec, size_t index) {               \
    if (index >= vec->length) {                                                \
      fprintf(stderr, "Index out of bounds\n");                                \
    }                                                                          \
    return vec->data[index];                                                   \
  }                                                                            \
                                                                               \
  /* Function to set an item in the vector at a specific index */              \
  void vec_##type##_set(VEC(type) *vec, size_t index, type item) {          \
    if (index >= vec->length) {                                                \
      return;                                                                  \
    }                                                                          \
    vec->data[index] = item;                                                   \
  }                                                                            \
                                                                               \
  /* Function to get the current size of the vector */                         \
  size_t vec_##type##_length(const VEC(type) *vec) { return vec->length; }  \
                                                                               \
  type vec_##type##_remove(VEC(type) *vec, size_t index) {                  \
    if (index >= vec->length) {                                                \
      fprintf(stderr, "Index out of bounds\n");                                \
    }                                                                          \
                                                                               \
    type popped_element = vec->data[index];                                    \
                                                                               \
    for (size_t i = index; i < vec->length - 1; ++i) {                         \
      vec->data[i] = vec->data[i + 1];                                         \
    }                                                                          \
                                                                               \
    vec->length--;                                                             \
                                                                               \
    if (vec->length < vec->capacity / 2) {                                     \
      vec->capacity /= 2;                                                      \
      vec->data = (type *)realloc(vec->data, vec->capacity * sizeof(type ));   \
      if (vec->data == NULL) {                                                 \
        fprintf(stderr, "Memory reallocation failed\n");                       \
        exit(EXIT_FAILURE);                                                    \
      }                                                                        \
    }                                                                          \
                                                                               \
    return popped_element;                                                     \
  }                                                                            \
                                                                               \
  type vec_##type##_pop(VEC(type) *vec) {                                   \
    return vec_##type##_remove(vec, vec->length - 1);                          \
  }

// clang-format off
#define DEFINE_VEC_EXPORTS(type) typedef struct {                              \
    type *data;                                                                \
    size_t length;                                                             \
    size_t capacity;                                                           \
  } vec_##type##_t;                                                            \
                                                                               \
  VEC(type) vec_##type##_new();                                            \
                                                                               \
  VEC(type) vec_##type##_new_with_size(size_t initial_size);               \
                                                                               \
  /* Function to free the memory used by the vector */                         \
  void vec_##type##_free(VEC(type) * vec);                                  \
                                                                               \
  /* Function to add an item to the vector */                                  \
  void vec_##type##_push_back(VEC(type) * vec, type item);                  \
                                                                               \
  void vec_##type##_push_front(VEC(type) *vec, type item);                  \
                                                                               \
  /* Function to get an item from the vector at a specific index */            \
  type vec_##type##_get(const VEC(type) *vec, size_t index);                \
                                                                               \
  /* Function to set an item in the vector at a specific index */              \
  void vec_##type##_set(VEC(type) *vec, size_t index, type item);           \
                                                                               \
  /* Function to get the current size of the vector */                         \
  size_t vec_##type##_length(const VEC(type) *vec);                         \
                                                                               \
  type vec_##type##_remove(VEC(type) *vec, size_t index);                   \
                                                                               \
  type vec_##type##_pop(VEC(type) *vec);
