cmake_minimum_required(VERSION 3.20)
project(LinkedListDemo)

#set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD 14)

#set(INC_DIR ./curl)

#include_directories(curl)

add_executable(LinkedListDemo main.cpp myFunc.h func.cpp constants.h)

#target_link_libraries(LinkedListDemo curl)
