cmake_minimum_required(VERSION 4.1)
project(client)

set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(client src/main.cc)
