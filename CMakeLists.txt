cmake_minimum_required(VERSION 3.10)
project(picontroller)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(/home/importly/cmake-test2/rootfs/usr/include)
LINK_DIRECTORIES(/home/importly/cmake-test2/rootfs/lib)
add_executable(picontroller main.cpp)
TARGET_LINK_LIBRARIES(picontroller pthread pigpio rt)