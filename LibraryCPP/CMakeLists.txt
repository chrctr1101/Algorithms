cmake_minimum_required(VERSION 3.10)

set(LIBRARY_SOURCES
    array.cpp
    list.cpp
    queue.cpp
    stack.cpp
    vector.cpp
)

add_library(LibraryCPP STATIC ${LIBRARY_SOURCES})

# ВАЖНО: делаем include директорию PUBLIC
target_include_directories(LibraryCPP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})