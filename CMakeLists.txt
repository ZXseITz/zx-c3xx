# cmake_minimum_required(VERSION <specify CMake version here>)
project(ZX_3CXX)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

add_library(ZX_3CXX library.cpp library.h Exchanger.cpp Exchanger.h)