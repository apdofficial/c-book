include(CTest)

add_executable(test_book)
target_sources(test_book PRIVATE test_book.c)
target_link_libraries(test_book PRIVATE book)
target_compile_features(test_book PRIVATE c_std_11)
target_compile_options(test_book PRIVATE -Wall -Wextra -Werror -Wno-deprecated)

add_test(test_book test_book)
