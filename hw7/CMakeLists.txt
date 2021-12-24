cmake_minimum_required(VERSION 3.20)
project(hw6)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(hw6 main.cpp)
target_link_libraries(hw6 ${OpenCV_LIBS})
