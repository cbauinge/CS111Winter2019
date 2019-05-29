add_executable(HelperTest Testframe.cpp)
target_link_libraries(HelperTest Helper gtest_main)

add_test(HelperTest HelperTest)