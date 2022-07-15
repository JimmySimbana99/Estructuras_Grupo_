cmake_minimum_required(VERSION 3.0.0)
project(rejo_negro VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(rejo_negro main.cpp Arbol.h Nodo.h Menu.h Menu.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
