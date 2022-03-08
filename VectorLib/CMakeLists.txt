cmake_minimum_required(VERSION 3.21)
project(VectorLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(FIND_NUMBERLIB_PATHS ../NumberLib)

find_path(NUMBERLIB_INCLUDE_DIR Number.h
        PATHS ${FIND_NUMBERLIB_PATHS})

include_directories(${NUMBERLIB_INCLUDE_DIR})

add_library(VectorLib SHARED Vector.cpp Vector.h)
