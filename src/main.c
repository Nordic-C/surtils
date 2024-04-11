#include "collections/set.h"
#include <unistd.h>

int main(void) {
  Set *mySet = newSet();
  set_add(mySet, 10);
  set_add(mySet, 230);
  set_add(mySet, 130);
  set_add(mySet, 140);
  set_print(mySet);
  return 0;
}