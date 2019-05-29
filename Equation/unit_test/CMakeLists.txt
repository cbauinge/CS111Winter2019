add_executable(EquationTest Testframe.cpp)
target_link_libraries(EquationTest Equation gtest_main)

add_test(EquationTest EquationTest)