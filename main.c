#include <stdio.h>
#include "collections/vec.h"
#include "logging/logger.h"

int main() {
    Vec *myVec = newVec();
    vec_push(myVec, 89);
    vec_push(myVec, 99);
    int *val = vec_get(myVec, 1);
    printf("val: %d\n", *val);
    size_t len = vec_length(myVec);
    printf("Len: %zu\n", len);
    vec_free(myVec);
    LOG(ERROR, "Hello");
    return 0;
}
