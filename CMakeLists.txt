cmake_minimum_required(VERSION 3.17)
project(task1BSU)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O0")

add_library(drinks.hpp INTERFACE)
add_executable(task1BSU main.cpp)

