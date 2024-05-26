#include "dyn_string.h"
#include <stddef.h>
#include <string.h>

dyn_string_t *new_dyn_string() {
    dyn_string_t *string;
    string->inner = new_vec();
    return string;
}

dyn_string_t *new_dyn_string_from_lit(char *literal) {
    dyn_string_t *string = new_dyn_string();
    for (int i = 0; i < strlen(literal); i++) {
        vec_push(string->inner, &literal[i]);
    }
    return string;
}

char dyn_string_get(size_t index) {
    
}
