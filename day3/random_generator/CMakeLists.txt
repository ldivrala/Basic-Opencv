cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "/bin/gcc")
set(CMAKE_CXX_COMPILER "/bin/c++")
project(Random)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( "/usr/local/include/" )
add_executable( Random Random.cpp )
target_link_libraries(Random ${OpenCV_LIBS})