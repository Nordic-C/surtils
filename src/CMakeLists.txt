cmake_minimum_required(VERSION 3.0)
project(src/util C)

set(CMAKE_C_STANDARD 23)

add_executable(
        src/main.c
        src/collections/vec.h
        src/collections/vec.c
        src/collections/set.h
        src/util/utils.h
        src/util/utils.c
        src/logging/logger.h
        src/logging/logger.c
        src/collections/set.c
        src/main.c)
