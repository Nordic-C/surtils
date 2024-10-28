#include "collections/vec.h"
#include "generics/iter.h"
#include "generics/set.h"
#include "generics/vec.h"
#include "strings/dyn_string.h"
#include "surtests/src/tests.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef char *string_t;

DEFINE_SET_EXPORTS(string_t);

DEFINE_SET(string_t);

DEFINE_VEC_EXPORTS(int);

DEFINE_VEC(int);

bool str_cmp(const string_t *s1, const string_t *s2) {
  printf("Comparing: %s, %s\n", *s1, *s2);
  return strcmp(*s1, *s2) == 0;
}

int main(void) {
  TEST(test_generic_sets, {
    SET(string_t) set = set_new_cmp(string_t, str_cmp);

    char *t = "Defg";
    char *v = "Defg";

    set_insert(string_t, &set, "aefg");
    set_insert(string_t, &set, "gefg");
    set_insert(string_t, &set, v);
    set_insert(string_t, &set, t);
    set_insert(string_t, &set, "Abce");

    size_t index = set_indexof(string_t, &set, "Defg");

    FOREACH(string_t, set, elem, {
      printf("Elem: %s\n", elem);
    });
  });

  TEST(test_generic_vectors, {
    VEC(int) my_vec = vec_new(int);

    vec_push_back(int, &my_vec, 90);
    vec_push_back(int, &my_vec, 100);

    FOREACH(int, my_vec, elem, { printf("Elem: %d\n", elem); });
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
}
