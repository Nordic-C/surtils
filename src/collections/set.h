//
// Created by thepigcat on 2/27/24.
//

#pragma once

#include <stdbool.h>

typedef struct set Set;

Set *newSet();

bool set_add(Set *set, int val);

void set_remove(Set *set, size_t index);

void set_print(const Set *set);

void free_set(Set *set);