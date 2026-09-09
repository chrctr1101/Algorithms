cmake_minimum_required(VERSION 3.10)
project(Lab1CPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../LibraryCPP/Tests ${CMAKE_BINARY_DIR}/LibraryCPP_Tests)

add_executable(Lab1CPP lab1.cpp)
target_include_directories(Lab1CPP PUBLIC ../LibraryCPP)
target_link_libraries(Lab1CPP LibraryCPP)

enable_testing()

add_test(NAME test1_task1 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/input11.txt
)
set_property(TEST test1_task1 PROPERTY PASS_REGULAR_EXPRESSION "2 3 5 7 11 0 0 0 0 0 \n2")

add_test(NAME test2_task1 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/input12.txt
)
set_property(TEST test2_task1 PROPERTY PASS_REGULAR_EXPRESSION "2 3 5 7 11 13 17 19 0 0 0 0 0 0 0 0 0 0 0 0 \n1")

add_test(NAME test1_task2 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/input21.txt
)
set_property(TEST test1_task2 PROPERTY PASS_REGULAR_EXPRESSION "2 2 2 3 5 7 11 13 17 0 0 0 0 0 0 0 0 0 0 0 \n2")

add_test(NAME test2_task2 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/input22.txt
)
set_property(TEST test2_task2 PROPERTY PASS_REGULAR_EXPRESSION "2 3 5 0 0 0 \n1")
add_custom_target(test_all
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS Lab1CPP
    COMMENT "Running all tests..."
)