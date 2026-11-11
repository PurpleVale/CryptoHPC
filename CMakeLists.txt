##############################################
#              Project Setup                 #
##############################################
cmake_minimum_required(VERSION 3.28.0)

project(CryptoHPC LANGUAGES CXX)

include_directories(src)

file(MAKE_DIRECTORY ./bin ./lib)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)

add_subdirectory(src/gui bin)
add_subdirectory(src/cryptohpc lib)

add_executable(test src/main.cpp)
target_link_libraries(test keymanager)