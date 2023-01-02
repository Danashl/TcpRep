cmake_minimum_required(VERSION 3.17)
project(TcpRep)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(server server.cpp
        DistanceClass.cpp
        DistanceClass.h
        Knn.cpp
        Knn.h
        )
add_executable(client client.cpp)
