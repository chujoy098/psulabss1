cmake_minimum_required(VERSION 4.1)
project(lab3_frommobile)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab3_frommobile
        main.cpp
        main.h
        proc13.cxx
        proc27.cxx
        proc43.cxx
        reccur18.cxx
        thetri15.cxx)
