cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "/bin/gcc")
set(CMAKE_CXX_COMPILER "/bin/c++")
project(TemplateMatching)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(TemplateMatching TemplateMatching.cpp)
target_link_libraries(TemplateMatching ${OpenCV_LIBS})