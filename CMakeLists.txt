cmake_minimum_required(VERSION 3.0)
project(FEMSolverCS111 CXX)

#Set Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB Sources "*.cpp")
list(REMOVE_ITEM Sources ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/testframe.cpp)
message(STATUS "${Sources}")
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

#check if Lapacke is installed. Not really necessary
find_package(LAPACKE)

#install eigen. Delivered with source
find_package(Eigen3 REQUIRED)

#check if gtest is installed. Required for unit testing
find_package(GTest REQUIRED)
find_package (Threads REQUIRED) #pthreads for gtest
#add_custom_target(unit-test COMMAND ./${CMAKE_CURRENT_SOURCE_DIR}/TestExe)

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

include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR} ${EIGEN3_INCLUDE_DIR} ${LAPACKE_INCLUDE_DIR} ${LAPACK_INCLUDE_DIR})
add_executable(SolverExe Main.cpp ${Sources})
target_link_libraries (SolverExe Eigen3::Eigen lapack lapacke)

add_executable(TestExe testframe.cpp ${Sources})
target_link_libraries(TestExe ${GTEST_BOTH_LIBRARIES} Eigen3::Eigen lapack lapacke ${CMAKE_THREAD_LIBS_INIT})
