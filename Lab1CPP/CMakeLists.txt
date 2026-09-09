cmake_minimum_required(VERSION 3.10)

add_executable(Lab1CPP lab1.cpp)
add_subdirectory(../LibraryCPP/Tests ${CMAKE_BINARY_DIR}/LibraryCPP_Tests)
# Линкуем библиотеку (она автоматически передаст include пути)
target_link_libraries(Lab1CPP PRIVATE LibraryCPP)

# Копируем input.txt
configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)