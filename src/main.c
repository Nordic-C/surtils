#include <stdio.h>
#include "collections/vec.h"
#include "logging/logger.h"
#include "collections/set.h"

int main(void) {
    Set *set = newSet();
    set_add(set, 100);
    set_add(set, 200);
    set_add(set, 100);
    set_add(set, 300);
    set_print(set);
}
