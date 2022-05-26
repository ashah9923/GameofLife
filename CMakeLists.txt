cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)  #c++ standard version

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GAMEOFLIFE2 VERSION 1.0)  #project name

add_executable(${PROJECT_NAME} src/main.cpp
)  #goes before include directory

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)