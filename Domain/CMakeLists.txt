include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Domain 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Domain.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Edge.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Element.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Mesh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Simplex.cpp)

add_subdirectory(unit_test)