#include <malloc.h>
#include <stdlib.h>
#include "set.h"

typedef struct _ {
    size_t length;
    int *data;
} Set;

Set *newSet() {
    Set *set = (Set *) malloc(sizeof(Set));
    set->length = 0;
    set->data = NULL;
    return set;
}

bool set_add(Set *set, int val) {
    for (int i = 0; i < set->length; ++i) {
        if (set->data[i] == val) {
            return false;
        }
    }

    set->length++;
    set->data = (int *) realloc(set->data, set->length * sizeof(int));
    if (set->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    set->data[set->length - 1] = val;

    return true;
}

void set_remove(Set *set, size_t index) {

}

void set_print(const Set *set) {
    printf("Set: ");
    for (size_t i = 0; i < set->length; ++i) {
        printf("%d ", set->data[i]);
    }
    printf("\n");
}

void set_free(Set *set) {
    free(set->data);
    set->length = 0;
    free(set);
}

size_t set_length(Set *set) {
    return set->length;
}
