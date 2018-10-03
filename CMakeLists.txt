cmake_minimum_required(VERSION 3.12)
project(metalog)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR})
SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")

add_executable(metalog main.cc)