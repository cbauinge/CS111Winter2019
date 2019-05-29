include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/Domain/include)

add_library(Helper 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Meshgenerator.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Multiindex.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Polynomial.cpp)

    target_link_libraries(Helper Domain)

add_subdirectory(unit_test)