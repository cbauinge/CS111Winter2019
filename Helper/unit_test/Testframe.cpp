#include "Meshgenerator.h"
#include "Multiindex.h"
#include "Polynomial.h"
#include "Vector.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/////////////////////////////////UNIT TESTS FOR MESHGENERATOR CLASS////////////

class MeshgeneratorTest : public ::testing::Test
{
protected:
    void SetUp() override {}

    Meshgenerator test_;
};

TEST_F(MeshgeneratorTest, NumberOfNodes)
{
    for (int i = 0; i < 10; i++)
    {
        std::srand(std::time(NULL));
        int n = std::rand() % 10 + 1; //random number between 1 and 10
        const Mesh* mesh = test_.Generate(n);
        EXPECT_EQ((n+1)*(n+1), mesh->GetpNodes().size());
        delete mesh;
    }
}

TEST_F(MeshgeneratorTest, NumberOfInnerNodes)
{

    for (int i = 0; i < 10; i++)
    {
        std::srand(std::time(NULL));
        int n = std::rand() % 10 + 1; //random number between 1 and 10
        const Mesh* mesh = test_.Generate(n);
        EXPECT_EQ((n-1)*(n-1), mesh->GetpInnerNodes().size());
        delete mesh;
    }
}

TEST_F(MeshgeneratorTest, NumberOfEdges)
{

    for (int i = 0; i < 10; i++)
    {
        std::srand(std::time(NULL));
        int n = std::rand() % 10 + 1; //random number between 1 and 10
        const Mesh* mesh = test_.Generate(n);
        EXPECT_EQ(2*n*(n+1) + n*n, mesh->GetpEdges().size());
        delete mesh;
    }
}


/////////////////////////////////UNIT TESTS FOR MULTIINDEX CLASS////////////


class MultiindexTest : public ::testing::Test
{
protected:
    void SetUp() override {
        std::vector<int> tmp{1, 2, 3};
        test_ = Multiindex(tmp);
    }

    Multiindex test_;
};


TEST_F(MultiindexTest, Abs)
{
    EXPECT_EQ(6, test_.abs());
}


TEST_F(MultiindexTest, AccessOperatorRead)
{
    EXPECT_EQ(1, test_[0]);
    EXPECT_EQ(2, test_[1]);
    EXPECT_EQ(3, test_[2]);
}

TEST_F(MultiindexTest, AccessOperatorWrite)
{
    std::srand(std::time(NULL));
    int n = std::rand() % 10;
    test_[0] = n;
    EXPECT_EQ(n, test_[0]);

    std::srand(std::time(NULL));
    n = std::rand() % 10;
    test_[1] = n;
    EXPECT_EQ(n, test_[1]);

}


/////////////////////////////////UNIT TESTS FOR POLYNOMIAL CLASS////////////


class PolynomialTest : public ::testing::Test
{
protected:
    void SetUp() override {
        test_ = Polynomial(2, 1);
    }

    Polynomial test_;

};


TEST_F(PolynomialTest, Dimension)
{
    EXPECT_EQ(2, test_.GetDimension());
}


TEST_F(PolynomialTest, Access1)
{
    std::vector<int> v{1, 0};
    test_.GetCoefficients()[Multiindex(v)] = 1.5; 
    EXPECT_EQ(1.5, test_.GetCoefficients()[Multiindex(v)]);
}

TEST_F(PolynomialTest, Access2)
{
    std::vector<int> v{0, 1};
    test_.GetCoefficients()[Multiindex(v)] = 1.5; 
    EXPECT_EQ(1.5, test_.GetCoefficients()[Multiindex(v)]);
}

TEST_F(PolynomialTest, Derivative)
{
    std::vector<int> v{1, 0};
    test_.GetCoefficients()[Multiindex(v)] = 1.5; 
    Polynomial d = test_.Derivative(0);
    v = std::vector<int>{0, 0};
    EXPECT_EQ(1.5, d.GetCoefficients()[Multiindex(v)]);
}


/////////////////////////////////UNIT TESTS FOR VECTOR CLASS////////////


class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override {
        test_ = Vector<int>(3);
        test_[0] = 1;
        test_[1] = 2;
        test_[2] = 3;
    }

    Vector<int> test_;
};


TEST_F(VectorTest, Access)
{
    EXPECT_EQ(1, test_[0]);
    EXPECT_EQ(2, test_[1]);
    EXPECT_EQ(3, test_[2]);
}





