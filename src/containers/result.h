#pragma once

#define UNWRAP_OR_EXIT(result)                                                 \
  switch (result.type) {                                                       \
  case OK:                                                                     \
    break;                                                                     \
  case ERR:                                                                    \
    fprintf(stderr, "Error: %s\n", unwrap_err(&result).msg);                   \
    return 1;                                                                  \
  }

#define UNWRAP_OR_RETURN(result)                                               \
  switch (result.type) {                                                       \
  case OK:                                                                     \
    break;                                                                     \
  case ERR:                                                                    \
    return result;                                                             \
  }

typedef struct {
  char *msg;
} Error;

typedef union {
  void *ok;
  Error err;
} InnerResult;

typedef enum {
  OK,
  ERR,
} ResultType;

typedef struct {
  ResultType type;
  InnerResult result;
} Result;

Error new_error(char *msg);

Result ok(void *val);

Result err(Error err);

void *unwrap_ok(Result *result);

Error unwrap_err(Result *result);

void *expect(Result *result, char *msg);

Error expect_err(Result *result, char *msg);

int is_ok(Result *result);

int is_err(Result *result);
