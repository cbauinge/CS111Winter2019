include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Solver 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ConstantIntegrator.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EigenSolver.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Integrator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LapackSolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PolynomialShapeFunction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ShapeFunction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Solver.cpp)

add_subdirectory(unit_test)