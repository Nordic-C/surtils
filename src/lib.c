#include <stdio.h>
#include <unistd.h>
#include "collections/vec.h"

#define STRINGIFY(expr) #expr

#define TYPENAME(expr) STRINGIFY(typeof(z))

int main(void) {
  Vec *my_vec = new_vec();

  vec_push(my_vec, "Hello");
  vec_push(my_vec, "World");
  vec_push(my_vec, "its me");
  vec_remove(my_vec, 1);
  char *elem = vec_pop(my_vec);

  for (int i = 0; i < vec_length(my_vec); i++) {
    printf("%s\n", (char *)vec_get(my_vec, i));
  }

  printf("Popped element: %s\n", elem);
}
