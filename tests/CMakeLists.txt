cmake_minimum_required(VERSION 3.14)

include(FetchContent)
FetchContent_Declare(
    boost_ut
    GIT_REPOSITORY https://github.com/boost-ext/ut.git
    GIT_TAG        v2.0.0 
    OVERRIDE_FIND_PACKAGE
)

project(unicode_width_test LANGUAGES CXX)
find_package(boost_ut REQUIRED)
add_executable(unicode_width_test test.cpp)
target_link_libraries(unicode_width_test PRIVATE sc::unicode_width Boost::ut)
target_compile_features(unicode_width_test PRIVATE cxx_std_20)
add_test(
    NAME unicode_width_test
    COMMAND unicode_width_test
)
