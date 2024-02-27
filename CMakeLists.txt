cmake_minimum_required(VERSION 3.0)
project(utils C)

set(CMAKE_C_STANDARD 23)

add_executable(utils main.c
        collections/vec.h
        collections/vec.c
        collections/set.h
        utils/utils.h
        utils/utils.c
        logging/logger.h)
