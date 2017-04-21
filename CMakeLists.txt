cmake_minimum_required(VERSION 3.6)
project(lab4)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/lab4.cbp
        cmake-build-debug/Makefile
        AgglomerativeClustering.cpp
        AgglomerativeClustering.h
        Cluster.cpp
        Cluster.h
        CMakeLists.txt
        main.cpp
        PairDistance.h
        Point.cpp
        Point.h)

add_executable(lab4 ${SOURCE_FILES})