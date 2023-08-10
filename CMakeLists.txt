cmake_minimum_required(VERSION 3.15)
project(unicode_width)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(tests "${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp")
target_include_directories(tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(tests PROPERTIES CXX_STANDARD 17)
