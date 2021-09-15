cmake_minimum_required (VERSION 3.20.0)
project (visitor)

add_executable (reflective-visitor reflective-visitor.cpp)
add_executable (classic-visitor classic-visitor.cpp)
add_executable (cyclic-visitor cyclic-visitor.cpp)
add_executable (multimethod-visitor multimethod-visitor.cpp)
add_executable (test-prog test-prog.cpp)

