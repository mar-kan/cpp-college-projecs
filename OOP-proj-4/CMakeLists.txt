cmake_minimum_required(VERSION 3.17)
project(OOP_proj_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_proj_2
        Date.cpp Date.h
        Forum.cpp Forum.h
        Post.cpp Post.h
        PostList.cpp PostList.h
        PrintSorted.cpp PrintSorted.h
        Thread.cpp Thread.h
        ThreadList.cpp ThreadList.h
        Tree.cpp Tree.h
        main.cpp)