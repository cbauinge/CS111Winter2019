add_executable(IoTest Testframe.cpp)
target_link_libraries(IoTest Io gtest_main)

add_test(IoTest IoTest)