cmake_minimum_required(VERSION 3.0.0)
project(Reinas VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Reinas main.cpp
                Tablero.h
                Arbol.h Nodo.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
