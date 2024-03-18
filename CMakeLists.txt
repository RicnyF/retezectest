cmake_minimum_required(VERSION 3.27)
project(retezec)

set(CMAKE_CXX_STANDARD 17)

add_executable(retezec main.cpp
        retezec.h
        retezec.cpp)
