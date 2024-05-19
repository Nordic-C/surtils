#include <stdio.h>
#include <unistd.h>
#include "collections/vec.h"

#define STRINGIFY(expr) #expr

#define TYPENAME(expr) STRINGIFY(typeof(z))

int main(void) {
  Vec *my_vec = new_vec();

  vec_push(my_vec, "deez nuts");
  vec_push(my_vec, "ballz");
  vec_push(my_vec, "say gex");

  for (int i = 0; i < vec_length(my_vec); i++) {
    printf("%s\n", (char *)vec_get(my_vec, i));
  }
}