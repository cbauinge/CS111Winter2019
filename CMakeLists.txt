cmake_minimum_required(VERSION 3.0)
project(FEMSolverCS111 CXX)

#Set Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB Sources "*.cpp")
file(GLOB Headers ".h")

option(BUILD_DOCUMENTATION "Use Doxygen to create html documentation" ON)

#install packages
#install Lapack
find_package(LAPACK)
if (NOT LAPACK_FOUND)
    if (UNIX)
        #try to install it
        execute_process(COMMAND sudo apt-get install -y liblapack-dev liblapacke-dev)
        find_package(LAPACK REQUIRED)
    endif()

    if (NOT LAPACK_FOUND)
        message(FATAL_ERROR "Couldn't find or install LAPACK")
    endif()
endif()

#install Lapacke
find_package(LAPACKE)

#install eigen. Delivered with source
find_package(Eigen3 REQUIRED)

#install doxygen if necessary
if (BUILD_DOCUMENTATION)
    find_package(Doxygen)
    if (NOT DOXYGEN_FOUND)
        if (UNIX)
            execute_process(COMMAND sudo apt-get install -y doxygen graphviz)
            find_package(Doxygen)
            if (DOXYGEN_FOUND)
                add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile $WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)
            endif()
        endif()
    else()
        add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile $WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)
    endif()
endif()

include_directories(${PROJECT_SOURCE_DIR} ${EIGEN3_INCLUDE_DIR} ${LAPACKE_INCLUDE_DIR} ${LAPACK_INCLUDE_DIR})
add_executable(SolverExe ${Sources})
target_link_libraries (SolverExe Eigen3::Eigen lapack lapacke)



