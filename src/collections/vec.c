#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new vector
vec_t *vec_new() {
  vec_t *vec = (vec_t *)malloc(sizeof(vec_t));
  // TODO: Might want to use calloc for this
  vec->data = (void **)malloc(sizeof(void *));
  vec->capacity = 1;
  vec->length = 0;
  return vec;
}

vec_t *vec_new_with_size(size_t initial_size) {
  vec_t *vec = (vec_t *)malloc(sizeof(vec_t));
  vec->data = (void **)malloc(sizeof(void *) * initial_size);
  vec->capacity = initial_size;
  vec->length = 0;
  return vec;
}

static void vec_resize(vec_t *vec, int capacity) {
  void **items = (void **)realloc(vec->data, sizeof(void *) * capacity);
  if (items) {
    vec->data = items;
    vec->capacity = capacity;
  }
}

// This function assumes that there is enough room to push the elements back.
static void vec_push_elements_back(vec_t *vec, size_t offset) {
  for (size_t i = vec->length; i > 0; i--) {
    void *elem = vec->data[i-1];
    vec->data[i - 1 + offset] = elem;
  }
}

// Function to free the memory used by the vector
void vec_free(vec_t *vec) {
  free(vec->data);
  free(vec);
}

// Function to add an item to the vector
void vec_push_back(vec_t *vec, void *item) {
  if (vec->length == vec->capacity) {
    vec_resize(vec, vec->capacity * 2);
  }
  vec->data[vec->length++] = item;
}

void vec_push_front(vec_t *vec, void *item) {
  if (vec->length == vec->capacity) {
    vec_resize(vec, vec->capacity * 2);
  }
  vec_push_elements_back(vec, 1);
  vec->data[0] = item;
  vec->length++;
}

// Function to get an item from the vector at a specific index
void *vec_get(const vec_t *vec, size_t index) {
  if (index >= vec->length) {
    return NULL; // or handle error appropriately
  }
  return vec->data[index];
}

// Function to set an item in the vector at a specific index
void vec_set(vec_t *vec, size_t index, void *item) {
  if (index >= vec->length) {
    return; // or handle error appropriately
  }
  vec->data[index] = item;
}

// Function to get the current size of the vector
size_t vec_length(const vec_t *vec) { return vec->length; }

void *vec_remove(vec_t *vec, size_t index) {
  if (index >= vec->length) {
    fprintf(stderr, "Index out of bounds\n");
    return NULL;
  }

  void *popped_element = vec->data[index];

  for (size_t i = index; i < vec->length - 1; ++i) {
    vec->data[i] = vec->data[i + 1];
  }

  vec->length--;

  if (vec->length < vec->capacity / 2) {
    vec->capacity /= 2;
    vec->data = (void **)realloc(vec->data, vec->capacity * sizeof(void *));
    if (vec->data == NULL) {
      fprintf(stderr, "Memory reallocation failed\n");
      exit(EXIT_FAILURE);
    }
  }

  return popped_element;
}

void *vec_pop(vec_t *vec) { return vec_remove(vec, vec->length - 1); }
