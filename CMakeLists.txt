cmake_minimum_required(VERSION 3.8)
project(ls)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ls.h ls.cpp Ls_Normal.cpp Ls_Normal.h Ls_Recursive.cpp Ls_Recursive.h)
add_executable(ls ${SOURCE_FILES})