macro(set_compilation_settings NAME)
    set_target_properties(${NAME} PROPERTIES COMPILE_OPTIONS "-Wno-unused")
    target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_link_libraries(${NAME} PRIVATE book)
    target_compile_features(${NAME} PRIVATE c_std_11 cxx_std_11)
    target_compile_options(${NAME} PRIVATE -Wall -Wextra -Werror -Wno-deprecated)
endmacro(set_compilation_settings)

macro(add_example NAME SOURCE)
    add_executable(${NAME} ${SOURCE})
    set_compilation_settings(${NAME})
endmacro(add_example)

add_example(ch2 ch2.c)
add_example(ch3 ch3.c)
add_example(ch4 ch4.c)
add_example(ch5 ch5.c)
add_example(ch6 ch6.c)

