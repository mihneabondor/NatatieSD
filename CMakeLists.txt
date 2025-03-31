cmake_minimum_required(VERSION 3.30)
project(NatatieSD)

set(CMAKE_CXX_STANDARD 20)

add_executable(NatatieSD main.cpp VectorDinamic.h Rata.cpp Rata.h Culoar.cpp Culoar.h Pereche.cpp Pereche.h
        output.cpp
        output.h)
