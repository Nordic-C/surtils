#pragma once

#include <stdbool.h>
#include <stddef.h>

// NOTE: This set is unordered
// WARN: Do not use. this is nyi
typedef struct {
  size_t length;
  void **data;
} hashset_t;

hashset_t *new_hashset();

bool hashset_insert(hashset_t *set, void *value);

bool hashset_remove(hashset_t *set, size_t index);

bool hashset_contains(const hashset_t *set, void *value);

size_t hashset_length(const hashset_t *set);

void hashset_free(hashset_t *set);
