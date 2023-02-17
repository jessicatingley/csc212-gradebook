cmake_minimum_required(VERSION 3.23)
project(csc212_gradebook)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(csc212_gradebook
        Category.cpp
        Course.cpp
        Individual.cpp
        main.cpp
        test.cpp)
