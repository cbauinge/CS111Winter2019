cmake_minimum_required(VERSION 3.0)
project(FEMSolverCS111 CXX)

#Set Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB Sources "*.cpp")
file(GLOB Headers ".h")

option(BUILD_DOCUMENTATION "Use Doxygen to create html documentation" ON)
find_package(Eigen3 REQUIRED)
find_package(LAPACKE)
find_package(LAPACK)
if (BUILD_DOCUMENTATION)
    find_package(Doxygen)
    add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile $WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)
endif()

include_directories(${PROJECT_SOURCE_DIR} ${EIGEN3_INCLUDE_DIR} ${LAPACKE_INCLUDE_DIR} ${LAPACK_INCLUDE_DIR})
add_executable(SolverExe ${Sources})
target_link_libraries (SolverExe Eigen3::Eigen lapacke lapack)



