#include "vec.h"

#undef DEFINE_VEC

// clang-format off
#define DEFINE_VEC(type) typedef struct {                                 \
    type *data;                                                                \
    size_t length;                                                             \
    size_t capacity;                                                           \
  } vec_##type##_t;                                                                           \
                                                                               \
  vec_gt(type) *vec_##type##_new() {                                             \
    vec_gt(type) *vec = (vec_gt(type) *)malloc(sizeof(vec_gt(type)));          \
    vec->data = (type *)malloc(sizeof(type ));                                 \
    vec->capacity = 1;                                                         \
    vec->length = 0;                                                           \
    return vec;                                                                \
  }                                                                            \
                                                                               \
  vec_gt(type) *vec_##type##_new_with_size(size_t initial_size) {               \
    vec_gt(type) *vec = (vec_gt(type) *)malloc(sizeof(vec_gt(type)));          \
    vec->data = (type *)malloc(sizeof(type ) * initial_size);                \
    vec->capacity = initial_size;                                              \
    vec->length = 0;                                                           \
    return vec;                                                                \
  }                                                                            \
                                                                               \
  static void vec_##type##_resize(vec_gt(type) *vec, size_t capacity) {         \
    type *items = (type *)realloc(vec->data, sizeof(type ) * capacity);     \
    if (items) {                                                               \
      vec->data = items;                                                       \
      vec->capacity = capacity;                                                \
    }                                                                          \
  }                                                                            \
                                                                               \
  /* This function assumes that there is enough room to push the elements      \
   * back.*/                                                                   \
  static void vec_##type##_push_elements_back(vec_gt(type) *vec,                \
                                            size_t offset) {                   \
    for (size_t i = vec->length; i > 0; i--) {                                 \
      type elem = vec->data[i - 1];                                           \
      vec->data[i - 1 + offset] = elem;                                        \
    }                                                                          \
  }                                                                            \
                                                                               \
  /* Function to free the memory used by the vector*/                          \
  void vec_##type##_free(vec_gt(type) * vec) {                                   \
    free(vec->data);                                                           \
    free(vec);                                                                 \
  }                                                                            \
                                                                               \
  /* Function to add an item to the vector*/                                   \
  void vec_##type##_push_back(vec_gt(type) * vec, type item) {                  \
    if (vec->length == vec->capacity) {                                        \
      vec_##type##_resize(vec, vec->capacity * 2);                               \
    }                                                                          \
    vec->data[vec->length++] = item;                                           \
  }                                                                            \
                                                                               \
  void vec_##type##_push_front(vec_gt(type) *vec, type item) {                  \
    if (vec->length == vec->capacity) {                                        \
      vec_##type##_resize(vec, vec->capacity * 2);                               \
    }                                                                          \
    vec_##type##_push_elements_back(vec, 1);                                     \
    vec->data[0] = item;                                                       \
    vec->length++;                                                             \
  }                                                                            \
                                                                               \
  /* Function to get an item from the vector at a specific index*/             \
  type vec_##type##_get(const vec_gt(type) *vec, size_t index) {            \
    if (index >= vec->length) {                                                \
      fprintf(stderr, "Index out of bounds\n");                                \
    }                                                                          \
    return vec->data[index];                                                   \
  }                                                                            \
                                                                               \
  /* Function to set an item in the vector at a specific index*/               \
  void vec_##type##_set(vec_gt(type) *vec, size_t index, type item) {           \
    if (index >= vec->length) {                                                \
      return;                                                                  \
    }                                                                          \
    vec->data[index] = item;                                                   \
  }                                                                            \
                                                                               \
  /* Function to get the current size of the vector*/                          \
  size_t vec_##type##_length(const vec_gt(type) *vec) { return vec->length; }    \
                                                                               \
  type vec_##type##_remove(vec_gt(type) *vec, size_t index) {                   \
    if (index >= vec->length) {                                                \
      fprintf(stderr, "Index out of bounds\n");                                \
    }                                                                          \
                                                                               \
    type popped_element = vec->data[index];                                   \
                                                                               \
    for (size_t i = index; i < vec->length - 1; ++i) {                         \
      vec->data[i] = vec->data[i + 1];                                         \
    }                                                                          \
                                                                               \
    vec->length--;                                                             \
                                                                               \
    if (vec->length < vec->capacity / 2) {                                     \
      vec->capacity /= 2;                                                      \
      vec->data = (type *)realloc(vec->data, vec->capacity * sizeof(type )); \
      if (vec->data == NULL) {                                                 \
        fprintf(stderr, "Memory reallocation failed\n");                       \
        exit(EXIT_FAILURE);                                                    \
      }                                                                        \
    }                                                                          \
                                                                               \
    return popped_element;                                                     \
  }                                                                            \
                                                                               \
  type vec_##type##_pop(vec_gt(type) *vec) {                                    \
    return vec_##type##_remove(vec, vec->length - 1);                            \
  }                                                                            