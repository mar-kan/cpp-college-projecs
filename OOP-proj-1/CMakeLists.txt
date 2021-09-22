cmake_minimum_required(VERSION 3.16)
project(oop2021)

set(CMAKE_CXX_STANDARD 11)

add_executable(oop2021
        main.cpp SchoolBuilding.cpp SchoolBuilding.h Floor.cpp Floor.h Yard.cpp Yard.h Stair.cpp Stair.h Classroom.cpp Classroom.h Corridor.cpp Corridor.h Student.cpp Student.h Teacher.cpp Teacher.h utilities.cpp utilities.h)
