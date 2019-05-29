cmake_minimum_required(VERSION 3.0)
project(CS111 CXX)

#Set Standard
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTEST_PATH ${CMAKE_SOURCE_DIR}/../googletest)
add_subdirectory(${GTEST_PATH} ${CMAKE_BINARY_DIR}/gtest)

set(EIGEN_PATH ${CMAKE_SOURCE_DIR}/../eigen)
add_subdirectory(${EIGEN_PATH} ${CMAKE_BINARY_DIR}/eigen)

find_package(LAPACK REQUIRED)

include_directories(SYSTEM ${GTEST_PATH}/googletest/include)
include_directories(${EIGEN_PATH})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Domain/include)
include_directories(${CMAKE_SOURCE_DIR}/Equation/include)
include_directories(${CMAKE_SOURCE_DIR}/Io/include)
include_directories(${CMAKE_SOURCE_DIR}/Solver/include)
include_directories(${CMAKE_SOURCE_DIR}/Helper/include)


enable_testing()

add_subdirectory(Domain)
add_subdirectory(Equation)
add_subdirectory(Io)
add_subdirectory(Solver)
add_subdirectory(Helper)

add_executable(CS111 Main.cpp)
target_link_libraries(CS111 Domain Equation Io Solver Helper)