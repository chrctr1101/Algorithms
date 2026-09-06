# CMake generated Testfile for 
# Source directory: /home/chrctr/Algorithms/Lab1CPP
# Build directory: /home/chrctr/Algorithms/Lab1CPP/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_11 "/home/chrctr/Algorithms/Lab1CPP/build/bin/laba1" "/home/chrctr/Algorithms/Lab1CPP/tests/input11.txt" "/home/chrctr/Algorithms/Lab1CPP/build/tests/test_11_output.txt")
set_tests_properties(test_11 PROPERTIES  WORKING_DIRECTORY "/home/chrctr/Algorithms/Lab1CPP/build/tests" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;23;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;40;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_11_check "sh" "-c" "diff -bBw /home/chrctr/Algorithms/Lab1CPP/tests/expected11.txt /home/chrctr/Algorithms/Lab1CPP/build/tests/test_11_output.txt > /dev/null 2>&1 && exit 0 || exit 1")
set_tests_properties(test_11_check PROPERTIES  DEPENDS "test_11" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;32;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;40;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_12 "/home/chrctr/Algorithms/Lab1CPP/build/bin/laba1" "/home/chrctr/Algorithms/Lab1CPP/tests/input12.txt" "/home/chrctr/Algorithms/Lab1CPP/build/tests/test_12_output.txt")
set_tests_properties(test_12 PROPERTIES  WORKING_DIRECTORY "/home/chrctr/Algorithms/Lab1CPP/build/tests" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;23;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;41;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_12_check "sh" "-c" "diff -bBw /home/chrctr/Algorithms/Lab1CPP/tests/expected12.txt /home/chrctr/Algorithms/Lab1CPP/build/tests/test_12_output.txt > /dev/null 2>&1 && exit 0 || exit 1")
set_tests_properties(test_12_check PROPERTIES  DEPENDS "test_12" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;32;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;41;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_21 "/home/chrctr/Algorithms/Lab1CPP/build/bin/laba1" "/home/chrctr/Algorithms/Lab1CPP/tests/input21.txt" "/home/chrctr/Algorithms/Lab1CPP/build/tests/test_21_output.txt")
set_tests_properties(test_21 PROPERTIES  WORKING_DIRECTORY "/home/chrctr/Algorithms/Lab1CPP/build/tests" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;23;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;42;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_21_check "sh" "-c" "diff -bBw /home/chrctr/Algorithms/Lab1CPP/tests/expected21.txt /home/chrctr/Algorithms/Lab1CPP/build/tests/test_21_output.txt > /dev/null 2>&1 && exit 0 || exit 1")
set_tests_properties(test_21_check PROPERTIES  DEPENDS "test_21" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;32;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;42;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_22 "/home/chrctr/Algorithms/Lab1CPP/build/bin/laba1" "/home/chrctr/Algorithms/Lab1CPP/tests/input22.txt" "/home/chrctr/Algorithms/Lab1CPP/build/tests/test_22_output.txt")
set_tests_properties(test_22 PROPERTIES  WORKING_DIRECTORY "/home/chrctr/Algorithms/Lab1CPP/build/tests" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;23;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;43;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
add_test(test_22_check "sh" "-c" "diff -bBw /home/chrctr/Algorithms/Lab1CPP/tests/expected22.txt /home/chrctr/Algorithms/Lab1CPP/build/tests/test_22_output.txt > /dev/null 2>&1 && exit 0 || exit 1")
set_tests_properties(test_22_check PROPERTIES  DEPENDS "test_22" _BACKTRACE_TRIPLES "/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;32;add_test;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;43;add_test_case;/home/chrctr/Algorithms/Lab1CPP/CMakeLists.txt;0;")
