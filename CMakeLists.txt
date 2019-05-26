cmake_minimum_required(VERSION 3.14)
project(abstractVM)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_executable(abstractVM
        src/main.cpp
        src/Parser.cpp)
