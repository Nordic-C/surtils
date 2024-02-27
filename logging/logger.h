//
// Created by thepigcat on 2/27/24.
//

#pragma once

#include "../utils/utils.h"
#include <stdio.h>

#define LOG(level, msg, ...) { \
    switch (level) {      \
        case ERROR:       \
            printf("%s[ERROR]%s ", RED, WHITE);              \
            printf(msg, __VA_ARGS__);  \
            printf("\n");                  \
        case WARN:        \
        case INFO:        \
    }                     \
}

#define LOG(level, msg) { \
    switch (level) {      \
        case ERROR:       \
            printf("%s[ERROR]%s ", RED, WHITE);              \
            printf(msg);  \
            printf("\n");                  \
        case WARN:        \
        case INFO:        \
    }                     \
}

static void logErr(char *msg);

typedef enum {
    ERROR,
    WARN,
    INFO,
} LogLevel;