cmake_minimum_required (VERSION 3.20.0)
project (chain-reponsibility)

add_executable (CoR-pointer pointer-chain.cpp)

# find_package(Boost 1.66.0 COMPONENTS serialization)
find_package(Boost 1.66.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable (CoR-broker cor-broker.cpp)
    target_link_libraries(CoR-broker ${Boost_LIBRARIES})
endif()

