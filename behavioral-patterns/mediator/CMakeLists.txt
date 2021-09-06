cmake_minimum_required (VERSION 3.20.0)
project (mediator)


find_package(Boost 1.66.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable (broker-prog mediator-borker.cpp)
    target_link_libraries(broker-prog ${Boost_LIBRARIES})
endif()

add_subdirectory (chat-room)