cmake_minimum_required(VERSION 3.14)

project(cbook
    VERSION 0.1
    DESCRIPTION "My code notes for the book Effective C by Robert C. Seacord"
    HOMEPAGE_URL "https://github.com/apdofficial/c-book"
    LANGUAGES C CXX
)

# Add the source target
add_subdirectory(src)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # If we are in the root, add option to build tests
    option(CBOOK_BUILD_TESTS "Build tests" ON)
    option(CBOOK_BUILD_EXAMPLES "Build examples" ON)

    # Build examples
    if(CBOOK_BUILD_EXAMPLES)
        add_subdirectory(examples)
    endif()

    # Add tests
    if(CBOOK_BUILD_TESTS)
        enable_testing()
        add_subdirectory(tests)
    endif()

endif()

