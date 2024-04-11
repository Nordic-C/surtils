#include "utils.h"
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void printStackTrace() {
    void *callstack[128];
    int frames = backtrace(callstack, 128);
    char **strs = backtrace_symbols(callstack, frames);

    if (strs == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < frames; ++i) {
        printf("%s\n", strs[i]);
    }

    free(strs);
}
