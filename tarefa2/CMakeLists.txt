cmake_minimum_required(VERSION 3.29)

project(tarefa1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tarefa2
    robustos.cpp
    robustos.hpp

    bisseccao.cpp
    bisseccao.hpp

    falsaposicao.cpp
    falsaposicao.hpp

    rapidos.cpp
    rapidos.hpp

    pontofixo.cpp
    pontofixo.hpp

    newton.cpp
    newton.hpp

    secante.cpp
    secante.hpp

    main.cpp)

