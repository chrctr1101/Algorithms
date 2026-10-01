cmake_minimum_required(VERSION 3.10)
project(Lab2CPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../LibraryCPP/Tests ${CMAKE_BINARY_DIR}/LibraryCPP_Tests)

add_executable(script annoyingscript.cpp)
target_include_directories(script PUBLIC ../LibraryCPP)
target_link_libraries(script PRIVATE LibraryCPP)

enable_testing()

add_test(NAME script1_hello
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script1.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input1.txt
)
set_property(TEST script1_hello PROPERTY
    PASS_REGULAR_EXPRESSION "Hello, World!")

add_test(NAME script2_hello_2
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script2.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input1.txt
)
set_property(TEST script2_hello_2 PROPERTY
    PASS_REGULAR_EXPRESSION "Hello, World!")

add_test(NAME script3_cat_1
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script3.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input2.txt
)
set_property(TEST script3_cat_1 PROPERTY
    PASS_REGULAR_EXPRESSION "Hello, cat!")

add_test(NAME script4_cat_2
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script4.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input2.txt
)
set_property(TEST script4_cat_2 PROPERTY
    PASS_REGULAR_EXPRESSION "Hello, cat!")

add_test(NAME script5_truth_Y
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script5.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input3a.txt
)
set_property(TEST script5_truth_Y PROPERTY
    PASS_REGULAR_EXPRESSION "1")

add_test(NAME script5_truth_N
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script5.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input3b.txt
)
set_property(TEST script5_truth_N PROPERTY
    PASS_REGULAR_EXPRESSION "0")
        
add_test(NAME script6_calc
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script6.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input4.txt
)
set_property(TEST script6_calc PROPERTY
    PASS_REGULAR_EXPRESSION "Calculator\nEnter Operator \\( \\+ - \\* / % \\)\nFirst Number\nSecond Number\n8")

add_test(NAME script_7_guess
    COMMAND script
        ${CMAKE_CURRENT_SOURCE_DIR}/script7.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/input5.txt
)
set_property(TEST script_7_guess PROPERTY
    PASS_REGULAR_EXPRESSION "Pick a number between 1 - 10\nCorrect!")
