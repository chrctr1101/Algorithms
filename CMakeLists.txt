cmake_minimum_required(VERSION 3.10)
project(DataStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опция для сборки тестов
option(BUILD_TESTS "Build tests" ON)

# Добавляем библиотеку
add_subdirectory(LibraryCPP)

# Добавляем лабораторную работу
add_subdirectory(Lab1CPP)

# Добавляем тесты если нужно
if(BUILD_TESTS)
    add_subdirectory(LibraryCPP/Tests)
endif()