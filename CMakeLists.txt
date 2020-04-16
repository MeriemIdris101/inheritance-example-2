cmake_minimum_required(VERSION 3.10)
project(inheritance_example_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(inheritance_example_2 person.cpp person.h employee.cpp employee.h warrior.cpp warrior.h date.cpp date.h
        warriortest.cpp employeetest.cpp)