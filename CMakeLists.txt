cmake_minimum_required(VERSION "3.16")
project(cpp_back_to_basics)

find_package(fmt CONFIG REQUIRED)
find_package(FLTK CONFIG REQUIRED)

add_executable(color color.cpp)
target_link_libraries(color PRIVATE fmt::fmt)

add_executable(fltk_test fltk_test.cpp)
target_link_libraries(fltk_test PRIVATE fltk fltk_gl fltk_forms fltk_images)

add_executable(test_limits test_limits.cpp)