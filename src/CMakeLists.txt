add_library(book STATIC)

target_sources(book
   PRIVATE
        book.c
        linked_list.c
   PUBLIC
        linked_list.h
        book.h
)

set_target_properties(book PROPERTIES VERSION ${book_VERSION} SOVERSION ${book_VERSION_MAJOR})
target_compile_features(book PUBLIC c_std_11 cxx_std_11)
target_compile_options(book PRIVATE -Wall -Wextra -Werror -fno-strict-aliasing -Wno-deprecated)
target_include_directories(book PUBLIC ${CMAKE_CURRENT_LIST_DIR})
