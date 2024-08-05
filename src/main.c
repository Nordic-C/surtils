#include "generics/vec.h"
#include "surtests/src/tests.h"
#include <stdio.h>
#include <unistd.h>

typedef char *string_t;

DEFINE_VEC(char)
DEFINE_VEC(string_t)

int main(void) {
  vec_gt(string_t) *test = vec_new(string_t);

  vec_push_back(string_t, test, "ABC");

  string_t x = vec_get(string_t, test, 0);

  printf("%s\n", x);
  /*
  TEST(test_vectors, {
    vec_t *my_vec = vec_new();

    vec_push_back(my_vec, "Hello");
    vec_push_back(my_vec, "World");
    vec_push_back(my_vec, "its me");
    vec_remove(my_vec, 1);
    char *elem = vec_pop(my_vec);

    for (int i = 0; i < vec_length(my_vec); i++) {
      printf("%s\n", (char *)vec_get(my_vec, i));
    }

    printf("Popped element: %s\n", elem);
  });

  TEST(test_vec_push_front, {
    int x = 100;
    int y = 200;
    int z = 300;
    int w = 400;

    vec_t *my_vec = vec_new();

    vec_push_back(my_vec, &x);
    vec_push_back(my_vec, &w);

    for (size_t i = 0; i < my_vec->length; i++) {
      printf("val at pos %zu: %d\n", i, *(int *)vec_get(my_vec, i));
    }

    vec_push_front(my_vec, &y);

    for (size_t i = 0; i < my_vec->length; i++) {
      printf("val at pos %zu: %d\n", i, *(int *)vec_get(my_vec, i));
    }

    vec_free(my_vec);
  })

  TEST(test_vector_macro, {
    int x = 100;
    int y = 200;
    int z = 300;
    VEC_FROM(my_vec, &x, &y, &z);

    for (int i = 0; i < vec_length(my_vec); i++) {
      printf("%d\n", *(int *)vec_get(my_vec, i));
    }
  });

  TEST(test_dyn_string, {
    char *literal = "Hello, World.";
    dyn_string_t *my_str = new_dyn_string_from_slice(literal);
    char *new_literal = " I am the cool neighbor :>";
    dyn_string_push_multiple_back(my_str, new_literal);
    char string[dyn_string_length(my_str)];
    strcpy(string, my_str->data);
    puts(string);
    dyn_string_free(my_str);
  });

  TEST(test_dyn_string_push_front, {
    dyn_string_t *my_str = new_dyn_string();
    dyn_string_push_single_back(my_str, 'H');
    dyn_string_push_single_back(my_str, 'e');
    dyn_string_push_single_back(my_str, 'l');
    dyn_string_push_single_back(my_str, 'l');
    dyn_string_push_single_back(my_str, 'o');
    dyn_string_push_multiple_front(my_str, "World ");
    char *str = dyn_string_as_slice(my_str);
    printf("%s\n", str);
  });
  */
}
