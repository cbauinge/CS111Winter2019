cmake_minimum_required(VERSION 3.0)
project(FEMSolverCS111 CXX)

#Set Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB Sources "*.cpp")
file(GLOB Headers ".h")

find_package(Eigen3 REQUIRED)
find_package(LAPACKE)
find_package(LAPACK)

include_directories(${PROJECT_SOURCE_DIR} ${EIGEN3_INCLUDE_DIR} ${LAPACKE_INCLUDE_DIR} ${LAPACK_INCLUDE_DIR})
add_executable(SolverExe ${Sources})
target_link_libraries (SolverExe Eigen3::Eigen lapacke lapack)
#target_link_libraries (SolverExe lapacke lapack)



