cmake_minimum_required(VERSION 3.22)
project(outcoreSS)

set(CMAKE_CXX_STANDARD 20)

add_executable(outcoreSS main.cpp manageSaves.cpp manageSaves.h format.cpp)
