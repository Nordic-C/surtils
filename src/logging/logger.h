//
// Created by thepigcat on 2/27/24.
//

#pragma once

#include "../../utils/utils.h"
#include <stdio.h>

// TODO: migrate all of these macros to functions
#define LOG(level, msg, ...) { \
    switch (level) {      \
        case ERROR:       \
            printf("%s[ERROR]%s ", RED, WHITE);              \
            printf(msg, __VA_ARGS__);  \
            printf("\n");      \
            break;                       \
        case WARN:        \
            printf("%s[WARN]%s ", YELLOW, WHITE);              \
            printf(msg, __VA_ARGS__);  \
            printf("\n");                  \
            break;                       \
        case INFO:        \
            printf("%s[INFO]%s ", BLUE, WHITE);              \
            printf(msg, __VA_ARGS__);  \
            printf("\n");                  \
            break;             \
        default:               \
            THROW_ERROR("The provided log level: %s is invalid. Valid ones are: ERROR (0), WARN (1), INFO (2)", (int) level); \
    }                          \
    \
}

#define LOG(level, msg) { \
    switch (level) {      \
        case ERROR:       \
            printf("%s[ERROR]%s ", RED, WHITE);              \
            printf(msg);  \
            printf("\n");                  \
            break;                       \
        case WARN:        \
            printf("%s[WARN]%s ", YELLOW, WHITE);              \
            printf(msg);  \
            printf("\n");                  \
            break;                       \
        case INFO:        \
            printf("%s[INFO]%s ", BLUE, WHITE);              \
            printf(msg);  \
            printf("\n");                  \
            break;                       \
        default:               \
            THROW_ERROR("The provided log level: %s is invalid. Valid ones are: ERROR (0), WARN (1), INFO (2)", (int) level); \
    }                     \
}

typedef enum {
    ERROR,
    WARN,
    INFO,
    DEBUG,
} LogLevel;

void logMsg(LogLevel leve, const char *format, ...);
