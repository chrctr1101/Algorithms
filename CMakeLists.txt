cmake_minimum_required(VERSION 3.10)
project(Laba1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Библиотека массива
add_library(array_lib STATIC
    ${CMAKE_SOURCE_DIR}/LibraryCPP/array.cpp
)

target_include_directories(array_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/LibraryCPP
)

# Основная программа
add_executable(laba1 ${CMAKE_SOURCE_DIR}/Lab1CPP/lab1.cpp)
target_link_libraries(laba1 array_lib)

# ВКЛЮЧАЕМ ТЕСТЫ
enable_testing()

# Функция для добавления тестов
function(add_test_case TEST_NAME INPUT_FILE EXPECTED_FILE)
    # Копируем файлы в папку сборки
    configure_file(
        ${CMAKE_SOURCE_DIR}/${INPUT_FILE}
        ${CMAKE_BINARY_DIR}/tests/${INPUT_FILE}
        COPYONLY
    )
    configure_file(
        ${CMAKE_SOURCE_DIR}/${EXPECTED_FILE}
        ${CMAKE_BINARY_DIR}/tests/${EXPECTED_FILE}
        COPYONLY
    )
    
    # Добавляем тест
    add_test(
        NAME ${TEST_NAME}
        COMMAND $<TARGET_FILE:laba1> 
            ${CMAKE_BINARY_DIR}/tests/${INPUT_FILE} 
            ${CMAKE_BINARY_DIR}/tests/${TEST_NAME}_output.txt
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    )
    
    # Добавляем проверку
    add_test(
        NAME ${TEST_NAME}_check
        COMMAND ${CMAKE_COMMAND} -E compare_files 
            ${CMAKE_BINARY_DIR}/tests/${TEST_NAME}_output.txt
            ${CMAKE_BINARY_DIR}/tests/${EXPECTED_FILE}
    )
    set_tests_properties(${TEST_NAME}_check PROPERTIES DEPENDS ${TEST_NAME})
endfunction()

# Добавляем тесты
add_test_case(test_11 "input11.txt" "expected11.txt")
add_test_case(test_12 "input12.txt" "expected12.txt")
add_test_case(test_21 "input21.txt" "expected21.txt")
add_test_case(test_22 "input22.txt" "expected22.txt")

message(STATUS "CMake configuration complete. Tests are ready.")