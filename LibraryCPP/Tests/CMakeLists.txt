cmake_minimum_required(VERSION 3.10)

# Находим все тесты
file(GLOB TEST_SOURCES "*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    add_executable(test_${TEST_NAME} ${TEST_SOURCE})
    
    # Линкуем библиотеку (она автоматически передаст include пути)
    target_link_libraries(test_${TEST_NAME} PRIVATE LibraryCPP)
    
    message(STATUS "Created test: test_${TEST_NAME}")
endforeach()

# Или объединяем все тесты в один
# add_executable(tests_all ${TEST_SOURCES})
# target_link_libraries(tests_all PRIVATE LibraryCPP)