cmake_minimum_required(VERSION 3.17)
project(Askisi3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Askisi3 main.cpp
        Class.cpp Class.h
        Corridor.cpp Corridor.h
        Floor.cpp Floor.h
        JuniorClass.h
        JuniorStudent.h
        Person.cpp Person.h
        Room.cpp Room.h
        SchoolBuilding.cpp SchoolBuilding.h
        SeniorClass.h
        SeniorStudent.h
        Stair.h Stair.cpp
        Student.cpp Student.h
        Teacher.cpp Teacher.h
        utilities.h utilities.cpp
        Yard.h)