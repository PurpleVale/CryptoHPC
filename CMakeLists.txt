##############################################
#              Project Setup                 #
##############################################
cmake_minimum_required(VERSION 3.28.0)

project(CryptoHPC LANGUAGES CXX C)

include_directories(headers)

file(MAKE_DIRECTORY ./bin ./lib)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

set(CMAKE_CXX_STANDARD 20)

add_executable(CryptoHPC src/main.cpp)
