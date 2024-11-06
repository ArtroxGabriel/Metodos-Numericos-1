cmake_minimum_required(VERSION 3.29)
project(tarefa1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tarefa1
    gabrigas_math.cpp
    gabrigas_math.hpp
    main.cpp)
