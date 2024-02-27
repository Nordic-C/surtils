//
// Created by thepigcat on 2/26/24.
//

#include <stdio.h>
#include "vec.h"
#include "../utils/utils.h"

typedef struct vec {
    int *data;
    size_t length;
    size_t capacity;
} Vec;

Vec *newVec() {
    Vec *vec = (Vec *) malloc(sizeof(Vec));
    vec->length = 0;
    vec->capacity = 1;
    vec->data = (int *) malloc(vec->capacity * sizeof(int));
    return vec;
}

void vec_push(Vec *vec, int value) {
    if (vec->length == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
        if (vec->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    vec->data[vec->length++] = value;
}

void vec_print(const Vec *vec) {
    printf("Vector: ");
    for (size_t i = 0; i < vec->length; ++i) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int *vec_get(const Vec *vec, size_t index) {
    if (index < vec->length) {
        return &vec->data[index];
    }

    fprintf(stderr, "Index %zu out of bounds for vector. Max is %zu\n", index, vec->length);
    printStackTrace();
    exit(EXIT_FAILURE);
}

void vec_free(Vec *vec) {
    free(vec->data);
    vec->length = 0;
    vec->capacity = 0;
    free(vec);
}

void vec_remove(Vec *vec, size_t index) {
    if (index >= vec->length) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    // Shift elements after the index
    for (size_t i = index; i < vec->length - 1; ++i) {
        vec->data[i] = vec->data[i + 1];
    }

    // Decrement the length to reflect the removal
    vec->length--;

    // Optionally, you can shrink the capacity if needed
    if (vec->length < vec->capacity / 2) {
        vec->capacity /= 2;
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
        if (vec->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

size_t vec_length(const Vec *vec) {
    return vec->length;
}