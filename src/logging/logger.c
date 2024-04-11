#include "logger.h"
#include <stdarg.h>
#include "../util/utils.h"

void logMsg(LogLevel level, const char *format, ...) {
    switch (level) {
        case ERROR:
            printf(RED "[Error]");
            break;
        case WARN:
            printf(YELLOW "[Warn]" );
            break;
        case INFO:
            printf(BLUE "[Info]");
            break;
        case DEBUG:
            printf(GREEN "[Debug]");
            break;
    }

    printf(WHITE " ");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

