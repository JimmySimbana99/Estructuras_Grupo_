cmake_minimum_required(VERSION 3.0.0)
project(proyecto_MJ VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(proyecto_MJ main.cpp
                            Lista.h Nodo.h
                            Menu.cpp Menu.h
                            Vehiculo.cpp Vehiculo.h
                            Mantenimiento.h Mantenimiento.cpp
                            Operacion.h
                            Validar.h Validar.cpp
                            Archivo.h
                            Usuario.h Usuario.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
