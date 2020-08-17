cmake_minimum_required(VERSION 3.16)
project(life_on_paper)

set(CMAKE_CXX_STANDARD 20)

add_executable(life_on_paper main.cpp BMP.h Table.cpp Table.h)