cmake_minimum_required(VERSION 3.17)
project(TcpRep)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TcpRep
        DistanceClass.cpp
        DistanceClass.h
        Knn.cpp
        Knn.h
        main.cpp)
