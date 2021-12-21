cmake_minimum_required(VERSION 3.5)
project(smo-tas-server)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(smo-tas-server src/common.cpp src/script.cpp src/smo-server.cpp include/common.h include/script.h include/server.h src/server.cpp include/tas.h include/packet.h src/packet.cpp)

find_package(Threads REQUIRED)
target_link_libraries(smo-tas-server PRIVATE Threads::Threads)