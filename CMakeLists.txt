cmake_minimum_required(VERSION 3.2)
project(ip_filter)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

add_subdirectory(src)
add_subdirectory(tst)
# add_subdirectory(lib/googletest)
include(GoogleTest)