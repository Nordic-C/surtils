#pragma once

#define SET(type) __set_##type##_t

#define set_new(type) __set_##type##_new()

#define set_new_cmp(type, cmp_fn) __set_##type##_new_cmp(cmp_fn)

#define set_new_sized(type, size) __set_##type##_new_with_size(size)

#define set_get(type, set, index) __set_##type##_get(set, index)

#define set_insert(type, set, elem) __set_##type##_insert(set, elem)

#define set_free(type, set) __set_##type##_free(set)

#define set_indexof(type, set, elem) __set_##type##_indexof(set, elem)

#define CMP_FN_T(name, type) _Bool (* name)(const type *, const type *)

// clang-format off
#define DEFINE_SET(type)                                                            \
                                                                                    \
  SET(type) __set_##type##_new() {                                                \
    SET(type) set;               \
    set.data = (type *)malloc(sizeof(type ));                                      \
    set.capacity = 1;                                                              \
    set.length = 0;                                                                \
    set.cmp_fn = NULL;                                                             \
    return set;                                                                     \
  }                                                                                 \
                                                                                    \
  SET(type) __set_##type##_new_cmp(CMP_FN_T(cmp_fn, type)) {                                                \
    SET(type) set;               \
    set.data = (type *)malloc(sizeof(type ));                                      \
    set.capacity = 1;                                                              \
    set.length = 0;                                                                \
    set.cmp_fn = cmp_fn;                                                           \
    return set;                                                                     \
  }                                                                                 \
                                                                                    \
  SET(type) __set_##type##_new_with_size(size_t initial_size) {                   \
    SET(type) set;               \
    set.data = (type *)malloc(sizeof(type ) * initial_size);                       \
    set.capacity = initial_size;                                                   \
    set.length = 0;                                                                \
    set.cmp_fn = NULL;\
    return set;                                                                     \
  }                                                                                 \
                                                                                    \
  static void __set_##type##_resize(SET(type) *set, size_t capacity) {             \
    type *items = (type *)realloc(set->data, sizeof(type ) * capacity);             \
    if (items) {                                                                    \
      set->data = items;                                                            \
      set->capacity = capacity;                                                     \
    }                                                                               \
  }                                                                                 \
                                                                                    \
  /* Function to free the memory used by the set */                                 \
  void __set_##type##_free(SET(type) *set) {                                       \
    free(set->data);                                                                \
    free(set);                                                                      \
  }                                                                                 \
                                                                                    \
  /* Function to add an item to the set */                                          \
  _Bool __set_##type##_insert(SET(type) *set, type item) {                         \
    if (set_indexof(type, set, item) != -1) return 0;                               \
    if (set->length == set->capacity) {                                             \
      __set_##type##_resize(set, set->capacity * 2);                                  \
    }                                                                               \
    set->data[set->length++] = item;                                                \
    return 1;                                                                       \
  }                                                                                 \
                                                                                    \
  /* Function to get an item from the settor at a specific index*/                  \
  type __set_##type##_get(const SET(type) *set, size_t index) {                    \
    if (index >= set->length) {                                                     \
      fprintf(stderr, "Index out of bounds\n");                                     \
    }                                                                               \
    return set->data[index];                                                        \
  }                                                                                 \
                                                                                    \
  /* Function to get the current size of the settor*/                               \
  size_t __set_##type##_length(const SET(type) *set) { return set->length; }       \
                                                                                    \
  type __set_##type##_remove(SET(type) *set, size_t index) {                       \
    if (index >= set->length) {                                                     \
      fprintf(stderr, "Index out of bounds\n");                                     \
    }                                                                               \
                                                                                    \
    type popped_element = set->data[index];                                         \
                                                                                    \
    for (size_t i = index; i < set->length - 1; ++i) {                              \
      set->data[i] = set->data[i + 1];                                              \
    }                                                                               \
                                                                                    \
    set->length--;                                                                  \
                                                                                    \
    if (set->length < set->capacity / 2) {                                          \
      set->capacity /= 2;                                                           \
      set->data = (type *)realloc(set->data, set->capacity * sizeof(type ));        \
      if (set->data == NULL) {                                                      \
        fprintf(stderr, "Memory reallocation failed\n");                            \
        exit(EXIT_FAILURE);                                                         \
      }                                                                             \
    }                                                                               \
                                                                                    \
    return popped_element;                                                          \
  }                                                                                 \
                                                                                    \
  ssize_t __set_##type##_indexof(SET(type) *set, type elem) {                      \
    for (size_t i = 0; i < set->length; i++) {                                      \
      type elem2 = set_get(type, set, i);                                           \
      if (set->cmp_fn == NULL ? elem == elem2 : set->cmp_fn(&elem, &elem2)) {       \
        return i;                                                                   \
      }                                                                             \
    }                                                                               \
    return -1;                                                                      \
  }                                                                                 \

// clang-format off
#define DEFINE_SET_EXPORTS(type) typedef struct {                                   \
    type *data;                                                                     \
    size_t length;                                                                  \
    size_t capacity;                                                                \
    CMP_FN_T(cmp_fn, type);                                                         \
  } __set_##type##_t;                                                                 \
                                                                                    \
  SET(type) __set_##type##_new();                                                 \
                                                                                    \
  SET(type) __set_##type##_new_cmp(CMP_FN_T(cmp_fn, type));                       \
                                                                                    \
  SET(type) __set_##type##_new_with_size(size_t initial_size);                    \
                                                                                    \
  /* Function to free the memory used by the set */                                 \
  void __set_##type##_free(SET(type) * set);                                       \
                                                                                    \
  /* Function to add an item to the set*/                                           \
  _Bool __set_##type##_insert(SET(type) * set, type item);                         \
                                                                                    \
  /* Function to get an item from the settor at a specific index */                 \
  type __set_##type##_get(const SET(type) *set, size_t index);                     \
                                                                                    \
  /* Function to get the current size of the set */                                 \
  size_t __set_##type##_length(const SET(type) *set);                              \
                                                                                    \
  type __set_##type##_remove(SET(type) *set, size_t index);                        \
                                                                                    \
  ssize_t __set_##type##_indexof(SET(type) *set, type elem);                       \
