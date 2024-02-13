cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

set(PROJECT_NAME HeapSort)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}

		src/HeapSort.hpp
		src/HeapSortTesting.cpp

)

target_include_directories(${PROJECT_NAME} PRIVATE src)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)
