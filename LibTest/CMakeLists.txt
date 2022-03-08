cmake_minimum_required(VERSION 3.21)
project(LibTest)

set(CMAKE_CXX_STANDARD 20)
set(FIND_NUMBERLIB_PATHS ../NumberLib)
set(FIND_VECTORLIB_PATHS ../VectorLib)

find_path(NUMBERLIB_INCLUDE_DIR Number.h
        PATHS ${FIND_NUMBERLIB_PATHS})

find_path(VECTORLIB_INCLUDE_DIR Vector.h
        PATHS ${FIND_VECTORLIB_PATHS})

include_directories(${NUMBERLIB_INCLUDE_DIR} ${VECTORLIB_INCLUDE_DIR})

find_library(NUMBERLIB_LIBRARY
        NAMES NumberLib
        PATH_SUFFIXES build
        PATHS ${FIND_NUMBERLIB_PATHS})

find_library(VECTORLIB_LIBRARY
        NAMES VectorLib
        PATH_SUFFIXES build
        PATHS ${FIND_VECTORLIB_PATHS})

add_executable(LibTest LibTest.cpp ${NUMBERLIB_LIBRARY} ${VECTORLIB_LIBRARY})

target_link_libraries(${PROJECT_NAME} ${NUMBERLIB_LIBRARY} ${VECTORLIB_LIBRARY})