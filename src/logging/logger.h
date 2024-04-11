#pragma once

#include "../util/utils.h"
#include <stdio.h>

typedef enum {
    ERROR,
    WARN,
    INFO,
    DEBUG,
} LogLevel;

void logMsg(LogLevel leve, const char *format, ...);
