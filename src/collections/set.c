#include <malloc.h>
#include <stdlib.h>

#include "set.h"

hashset_t *new_hashset() {
    return NULL;
}

bool hashset_insert(hashset_t *set, void *value);

bool hashset_remove(hashset_t *set, size_t index);

bool hashset_contains(const hashset_t *set, void *value);

void hashset_free(hashset_t *set);

size_t hashset_length(const hashset_t *set);
