cmake_minimum_required(VERSION 3.10)
project(Laba1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(array_lib STATIC
    include/array.cpp
)

target_include_directories(array_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(laba1 src/lab1.cpp)
target_link_libraries(laba1 array_lib)

enable_testing()

function(add_test_case TEST_NAME INPUT_FILE EXPECTED_FILE)
    add_test(
        NAME ${TEST_NAME}
        COMMAND $<TARGET_FILE:laba1> 
            ${CMAKE_SOURCE_DIR}/tests/${INPUT_FILE} 
            ${CMAKE_BINARY_DIR}/tests/${TEST_NAME}_output.txt
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    )
    
    # Используем diff с игнорированием пробелов в конце строк и пустых строк
    add_test(
        NAME ${TEST_NAME}_check
        COMMAND sh -c "diff -bBw ${CMAKE_SOURCE_DIR}/tests/${EXPECTED_FILE} ${CMAKE_BINARY_DIR}/tests/${TEST_NAME}_output.txt > /dev/null 2>&1 && exit 0 || exit 1"
    )
    set_tests_properties(${TEST_NAME}_check PROPERTIES DEPENDS ${TEST_NAME})
endfunction()

# Тесты
add_test_case(test_11 "input11.txt" "expected11.txt")
add_test_case(test_12 "input12.txt" "expected12.txt")
add_test_case(test_21 "input21.txt" "expected21.txt")
add_test_case(test_22 "input22.txt" "expected22.txt")

message(STATUS "CMake configuration complete. Tests are ready.")