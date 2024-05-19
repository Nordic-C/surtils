#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

#define INITIAL_CAPACITY 4

typedef struct vec {
    void **data;
    size_t length;
    size_t capacity;
} Vec;

// Function to create a new vector
Vec *new_vec() {
  Vec *vec = (Vec *)malloc(sizeof(Vec));
  vec->data = (void **)malloc(sizeof(void *) * INITIAL_CAPACITY);
  vec->capacity = INITIAL_CAPACITY;
  vec->length = 0;
  return vec;
}

static void vec_resize(Vec *vec, int capacity) {
  void **items = (void **)realloc(vec->data, sizeof(void *) * capacity);
  if (items) {
    vec->data = items;
    vec->capacity = capacity;
  }
}

// Function to free the memory used by the vector
void vec_free(Vec *vec) {
  free(vec->data);
  free(vec);
}

// Function to add an item to the vector
void vec_push(Vec *vec, void *item) {
  if (vec->length == vec->capacity) {
    vec_resize(vec, vec->capacity * 2);
  }
  vec->data[vec->length++] = item;
}

// Function to get an item from the vector at a specific index
void *vec_get(const Vec *vec, size_t index) {
  if (index < 0 || index >= vec->length) {
    return NULL; // or handle error appropriately
  }
  return vec->data[index];
}

// Function to set an item in the vector at a specific index
void vec_set(Vec *vec, size_t index, void *item) {
  if (index < 0 || index >= vec->length) {
    return; // or handle error appropriately
  }
  vec->data[index] = item;
}

// Function to get the current size of the vector
size_t vec_length(const Vec *vec) { return vec->length; }

// Function to resize the vector
