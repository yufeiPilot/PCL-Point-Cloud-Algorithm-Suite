cmake_minimum_required(VERSION 3.28)
project(PCL_Point_Cloud_Algorithm_Suite)

set(CMAKE_CXX_STANDARD 14)

include_directories(filter/include)

add_executable(PCL_Point_Cloud_Algorithm_Suite
        filter/include/pass_through_filter.h
        filter/source/pass_through_filter.cpp
        main.cpp)
