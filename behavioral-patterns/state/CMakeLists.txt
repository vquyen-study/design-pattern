cmake_minimum_required (VERSION 3.20.0)
project (state)

add_executable (classic-state-impl classic-state-impl.cpp)
add_executable (handmade-state handmade-state.cpp)

find_package(Boost 1.66.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable (sm-boost sm-boost.cpp)
    target_link_libraries(sm-boost ${Boost_LIBRARIES})
endif()
