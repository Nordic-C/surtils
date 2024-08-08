#include "lib.h"
#include "generics/vec.h"

DEFINE_VEC(int);

vec_gt(int) *get_s() {
    return vec_new_sized(int, 10);
}