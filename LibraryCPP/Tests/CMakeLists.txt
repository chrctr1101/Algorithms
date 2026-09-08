add_executable(TestArrayCPP array.cpp)
target_include_directories(TestArrayCPP Public ..)
target_link_librares(TestArrayCVPP LibraryCpp)
add_test(TestArrayCPP TestArrayCPP)
