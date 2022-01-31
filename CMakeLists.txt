cmake_minimum_required(VERSION "3.16")
project(cpp_back_to_basics)

find_package(fmt CONFIG REQUIRED)
find_package(FLTK CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D_WIN32_WINDOWS)

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
add_executable(hello_world hello_world.cpp)
add_executable(any std_any.cpp)

add_executable(test_string test_string.cpp)

add_executable(enable_if enable_if.cpp)
target_include_directories(enable_if BEFORE PUBLIC ${Boost_INCLUDE_DIRS})
# target_link_libraries(enable_if PRIVATE Boost::boost)

add_executable(http_client_boost http_client_boost.cpp)
target_link_libraries(http_client_boost PRIVATE Boost::boost fmt::fmt)

#  PATHS "C:/Qt/5.12.12/msvc2022-static/lib/cmake"
#  PATHS "C:/Qt/5.12.12/msvc2022-dynamic/lib/cmake"
# ²Î¿¼£º https://stackoverflow.com/a/49816516/12291425
find_package(Qt5 COMPONENTS Widgets Network REQUIRED PATHS "C:/Qt/5.12.12/msvc2022-dynamic/lib/cmake" NO_DEFAULT_PATH)


set(CMAKE_AUTOMOC ON)
add_executable(test_qt test_qt.cpp)
target_link_libraries(test_qt PRIVATE Qt5::Widgets Qt5::Network fmt::fmt)
# https://stackoverflow.com/a/40572207/12291425
add_custom_command(
    TARGET test_qt POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Widgets>
        $<TARGET_FILE:Qt5::Core>
        $<TARGET_FILE:Qt5::Network>
        $<TARGET_FILE_DIR:test_qt>
)

add_executable(http_server_sync http_server_sync.cpp)
target_link_libraries(http_server_sync PRIVATE Boost::boost)

add_executable(lambda_test lambda_test.cpp)
target_link_libraries(lambda_test PRIVATE fmt::fmt)