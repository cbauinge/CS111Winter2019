#include "gtest/gtest.h"
#include "Polynomial.h"
#include "Multiindex.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testPolynomial, Dimension)
{
    Polynomial p{3, 1};
    EXPECT_EQ(3, p.GetDimension());	
}

TEST(testPolynomial, Access)
{
    Polynomial p{1, 1};
    std::vector<int> v = {1};
    Multiindex m{v};
    double c = 1.123456;
    p.GetCoefficients()[m] = c;
    EXPECT_EQ(c, p.GetCoefficients()[m]);
}

TEST(testPolynomial, Size)
{
    Polynomial p{1, 1};
    std::vector<int> v = {1};
    Multiindex m{v};
    double c = 1.123456;
    p.GetCoefficients()[m] = c;
    EXPECT_EQ(1, p.GetCoefficients().size());
}


TEST(testMultiindex, Size)
{
    std::vector<int> v = {1, 0, 2, 0};
    Multiindex m{v};
    EXPECT_EQ(v.size(), m.size());
}

TEST(testMultiindex, Abs)
{
    std::vector<int> v = {1, 0, 2, 0};
    Multiindex m{v};
    EXPECT_EQ(3, m.abs());
}

TEST(testMultiindex, Access)
{
    std::vector<int> v = {1, 0, 2, 0};
    Multiindex m{v};
    EXPECT_EQ(1, m[0]);
    EXPECT_EQ(0, m[1]);
    EXPECT_EQ(2, m[2]);
}