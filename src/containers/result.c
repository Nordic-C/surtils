#include "result.h"
#include <stdio.h>
#include <stdlib.h>

Error new_error(char *msg) {
  Error err = {msg};
  return err;
}

Result ok(void *val) {
  Result result = {.type = OK, .result.ok = val};
  return result;
}

Result err(Error err) {
  Result result = {.type = ERR, .result.err = err};
  return result;
}

void *unwrap_ok(Result *result) {
  if (result->type != OK) {
    fprintf(stderr,
            "Attempt to unwrap an Result even though it holds an error\n");
    exit(1);
  }
  return result->result.ok;
}

Error unwrap_err(Result *result) {
  if (result->type != ERR) {
    fprintf(stderr, "Attempt to unwrap the error of an Result even though it\n"
                    "holds an ok value");
    exit(1);
  }
  return result->result.err;
}

inline int is_ok(Result *result) { return result->type == OK; }

inline int is_err(Result *result) { return !is_ok(result); }