include(CTest)

macro(add_test_file NAME)
    add_executable(${NAME})
    target_sources(${NAME} PRIVATE ${NAME}.c)
    set_target_properties(${NAME} PROPERTIES COMPILE_OPTIONS "-Wno-unused")
    target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_link_libraries(${NAME} PRIVATE book)
    target_compile_features(${NAME} PRIVATE c_std_11 cxx_std_11)
    target_compile_options(${NAME} PRIVATE -Wall -Wextra -Werror -Wno-deprecated)
    add_test(${NAME} ${NAME})
endmacro(add_test_file)

add_test_file(test_ch2)
add_test_file(test_ch3)
add_test_file(test_ch4)
add_test_file(test_ch5)



