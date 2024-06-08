#include "dyn_string.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

dyn_string_t *new_dyn_string() {
  dyn_string_t *string = (dyn_string_t *)malloc(sizeof(dyn_string_t));
  // TODO: Might want to use calloc for this
  string->data = (char *)malloc(sizeof(char));
  string->capacity = 1;
  string->length = 0;
  return string;
}

static dyn_string_t *new_string_with_size(size_t initial_size) {
  dyn_string_t *string = (dyn_string_t *)malloc(sizeof(dyn_string_t));
  string->data = (char *)malloc(sizeof(void *) * initial_size);
  string->capacity = initial_size;
  string->length = 0;
  return string;
}

dyn_string_t *new_dyn_string_from_slice(char *literal) {
  size_t str_len = strlen(literal);
  dyn_string_t *string;
  string = new_string_with_size(str_len);
  dyn_string_push_multiple(string, literal);
  return string;
}

char *dyn_string_get(const dyn_string_t *string, size_t index) {
  if (index < string->length) {
    return &string->data[index];
  }

  fprintf(stderr, "Index %zu out of bounds for dynamic string. Length is: %zu\n", index,
          string->length);
  exit(EXIT_FAILURE);
}

size_t dyn_string_length(const dyn_string_t *string) {
  return string->length;
}

static void string_resize(dyn_string_t *string, int capacity) {
  char *items = (char *)realloc(string->data, sizeof(char) * capacity);
  if (items) {
    string->data = items;
    string->capacity = capacity;
  }
}

static void string_push(dyn_string_t *string, char ch) {
  if (string->length == string->capacity) {
    string_resize(string, string->capacity * 2);
  }
  string->data[string->length++] = ch;
}

void dyn_string_push_single(dyn_string_t *string, char ch) {
  string_push(string, ch);
}

void dyn_string_push_multiple(dyn_string_t *string, char *chars) {
  for (int i = 0; i < strlen(chars); i++) {
    string_push(string, chars[i]);
  }
}

char *dyn_string_as_slice(dyn_string_t *string) {
  return string->data;
}

void dyn_string_free(dyn_string_t *string) {
  free(string->data);
  free(string);
  string = NULL;
}
