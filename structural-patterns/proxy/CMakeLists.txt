cmake_minimum_required (VERSION 3.20.0)
project (proxy)

add_executable (property-proxy property-proxy.cpp)
add_executable (virtual-proxy virtual-proxy.cpp)
add_executable (communication-proxy communication-proxy.cpp)
