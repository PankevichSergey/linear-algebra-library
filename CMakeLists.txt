cmake_minimum_required(VERSION 3.19)
project(linal)

set(CMAKE_CXX_STANDARD 17)

add_executable(linal main.cpp Num.cpp Num.h Mat.cpp Mat.h Vec.cpp Vec.h trash.cpp Perm.cpp Perm.h Poly.cpp Poly.h)