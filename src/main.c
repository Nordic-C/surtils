#include "collections/set.h"
#include "collections/vec.h"
#include <unistd.h>

int main(void) {
  Vec *myVec = newVec();
  for (int i = 0; i < 100; i++) {
    vec_push(myVec, i * 69);
  }
  vec_print(myVec);
}