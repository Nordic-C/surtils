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
  dyn_string_t *string = new_string_with_size(str_len);
  strcpy(string->data, literal);
  string->length += str_len;
  return string;
}

char *dyn_string_get(const dyn_string_t *string, size_t index) {
  if (index < string->length) {
    return &string->data[index];
  }

  fprintf(stderr,
          "Index %zu out of bounds for dynamic string. Length is: %zu\n", index,
          string->length);
  exit(EXIT_FAILURE);
}

size_t dyn_string_length(const dyn_string_t *string) { return string->length; }

static void string_resize(dyn_string_t *string, int capacity) {
  char *items = (char *)realloc(string->data, sizeof(char) * capacity);
  if (items) {
    string->data = items;
    string->capacity = capacity;
  }
}

static void string_push_chars_back(dyn_string_t *string, size_t offset) {
  for (size_t i = string->length; i > 0; i--) {
    char elem = string->data[i - 1];
    string->data[i - 1 + offset] = elem;
  }
}

static void string_push_back(dyn_string_t *string, char ch) {
  if (string->length == string->capacity) {
    string_resize(string, string->capacity * 2);
  }
  string->data[string->length++] = ch;
}

void dyn_string_push_single_front(dyn_string_t *string, char ch) {
  if (string->length == string->capacity) {
    string_resize(string, string->capacity * 2);
  }
  string_push_chars_back(string, 1);
  string->data[0] = ch;
  string->length++;
}

void dyn_string_push_multiple_front(dyn_string_t *string, char *chars) {
  size_t len = strlen(chars);
  if (string->length == string->capacity) {
    string_resize(string, string->capacity * 2);
  }
  string_push_chars_back(string, len);
  for (size_t i = 0; i < len; i++) {
    string->data[i] = chars[i];
  }
  string->length += len;
}

void dyn_string_push_single_back(dyn_string_t *string, char ch) {
  string_push_back(string, ch);
}

void dyn_string_push_multiple_back(dyn_string_t *string, char *chars) {
  size_t len = strlen(chars);
  for (int i = 0; i < len; i++) {
    string_push_back(string, chars[i]);
  }
}

char *dyn_string_as_slice(dyn_string_t *string) { return string->data; }

void dyn_string_free(dyn_string_t *string) {
  free(string->data);
  free(string);
  string = NULL;
}
