cmake_minimum_required(VERSION 3.27)
project(TallerEstructura1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TallerEstructura1
        Evento.cpp
        Evento.h
        main.cpp
        Persona.cpp
        Persona.h)
