cmake_minimum_required(VERSION 3.12)
project(metalog)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(metalog example/metalog.cc)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY example/ DESTINATION share/metalog/examples)
