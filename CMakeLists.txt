cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        ZergBot.cpp
        ZergBot.h)

add_executable(project ${SOURCE_FILES})