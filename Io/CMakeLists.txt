include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Io ${CMAKE_CURRENT_SOURCE_DIR}/src/Writer.cpp)

add_subdirectory(unit_test)