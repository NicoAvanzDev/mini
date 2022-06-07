cmake_minimum_required(VERSION 3.22)
project(mini C)

set(CMAKE_C_STANDARD 11)

add_executable(mini src/main.c src/lzw/lzw.c src/lzw/lzw.h src/ds/hashtable.c src/ds/hashtable.h)
