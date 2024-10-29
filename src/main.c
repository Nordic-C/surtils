#include "collections/vec.h"
#include "generics/iter.h"
#include "generics/map.h"
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

DEFINE_MAP_EXPORTS(int, int)
DEFINE_MAP(int, int)

bool str_cmp(const string_t *s1, const string_t *s2) {
  printf("Comparing: %s, %s\n", *s1, *s2);
  return strcmp(*s1, *s2) == 0;
}

int main(void) {
  TEST(test_maps, {
    MAP(int, int) map = map_new(int, int);
    FOREACH_ENTRY(int, int, map, key, value, {
      printf("%zu: k: %d, v: %d\n", __iter_index__, key, value);
    });
  });

  TEST(test_stacked_vecs, {
    typedef VEC(int) vec_int_t;
    DEFINE_VEC_EXPORTS(vec_int_t);
    VEC(vec_int_t) vec = vec_new(vec_int_t);
    FOREACH(vec_int_t, vec, value,
            { FOREACH(int, value, v, { printf("val: %d\n", v); }); });
  });

  TEST(test_generic_sets, {
    SET(string_t) set = set_new_cmp(string_t, NULL);

    char *t = "Defg";
    char *v = "Defg";

    set_insert(string_t, &set, "aefg");
    set_insert(string_t, &set, "gefg");
    set_insert(string_t, &set, v);
    set_insert(string_t, &set, t);
    set_insert(string_t, &set, "Abce");

    size_t index = set_indexof(string_t, &set, "Defg");

    FOREACH(string_t, set, elem, { printf("Elem: %s\n", elem); });
  });

  TEST(test_generic_vectors, {
    VEC(int) my_vec = vec_new(int);

    vec_push_back(int, &my_vec, 90);
    vec_push_back(int, &my_vec, 100);

    FOREACH(int, my_vec, v, { printf("Elem: %d\n", v); });
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
