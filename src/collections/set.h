#pragma once

#include <stdbool.h>
#include "stdlib.h"

typedef struct set Set;

Set *newSet();

bool set_add(Set *set, int val);

void set_remove(Set *set, size_t index);

void set_print(const Set *set);

void set_free(Set *set);

size_t set_length(Set *set);