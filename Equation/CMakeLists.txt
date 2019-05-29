include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Equation 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BoundaryCondition.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DirichletBC.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Equation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LaplaceEnergyFunction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SourceFunction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TestSourceFunction.cpp)

add_subdirectory(unit_test)