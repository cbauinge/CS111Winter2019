#include "gtest/gtest.h"
#include "Polynomial.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testPolynomial, myPolynomialTest1)
{
    Polynomial p{3, 1};
    EXPECT_EQ(3, p.GetDimension());	
}