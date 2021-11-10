cmake_minimum_required(VERSION "3.16")
project(cpp_back_to_basics)

find_package(fmt CONFIG REQUIRED)
find_package(FLTK CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(color color.cpp)
target_link_libraries(color PRIVATE fmt::fmt)

add_executable(fltk_test fltk_test.cpp)
target_link_libraries(fltk_test PRIVATE fltk fltk_gl fltk_forms fltk_images)

add_executable(limits limits.cpp)

add_library(print_hello print_hello.cpp)
target_link_libraries(print_hello fmt::fmt)

add_executable(hello hello.cpp)
target_link_libraries(hello print_hello)

add_executable(format format.cpp)
target_link_libraries(format PRIVATE fmt::fmt)

add_executable(ranges ranges.cpp)
target_link_libraries(ranges PRIVATE fmt::fmt range-v3 range-v3-meta range-v3::meta range-v3-concepts)

add_executable(deleted_methods deleted_methods.cpp)
target_link_libraries(deleted_methods PRIVATE fmt::fmt)
