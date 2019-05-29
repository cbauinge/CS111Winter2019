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
    {
        const Mesh* mesh = test_.Generate(1);
        EXPECT_EQ(0, mesh->GetpInnerNodes().size());
        delete mesh;
    }

    {
        const Mesh* mesh = test_.Generate(2);
        EXPECT_EQ(1, mesh->GetpInnerNodes().size());
        delete mesh;
    }

    {
        const Mesh* mesh = test_.Generate(3);
        EXPECT_EQ(4, mesh->GetpInnerNodes().size());
        delete mesh;
    }
}

TEST_F(MeshgeneratorTest, NumberOfEdges)
{
    {
        const Mesh* mesh = test_.Generate(1);
        EXPECT_EQ(5, mesh->GetpEdges().size());
        delete mesh;
    }

    {
        const Mesh* mesh = test_.Generate(2);
        EXPECT_EQ(16, mesh->GetpEdges().size());
        delete mesh;
    }

    {
        const Mesh* mesh = test_.Generate(3);
        EXPECT_EQ(33, mesh->GetpEdges().size());
        delete mesh;
    }
}


/////////////////////////////////UNIT TESTS FOR MULTIINDEX CLASS////////////


class MultiindexTest : public ::testing::Test
{

};


/////////////////////////////////UNIT TESTS FOR POLYNOMIAL CLASS////////////


class PolynomialTest : public ::testing::Test
{

};


/////////////////////////////////UNIT TESTS FOR VECTOR CLASS////////////


class VectorTest : public ::testing::Test
{

};





