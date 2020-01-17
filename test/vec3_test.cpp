#include "vec3.h"

#include <gtest/gtest.h>

TEST(Vec3Test, ConstructorAndGetter)
{
    Vec3 v0(2.2F, 3.8F, 44.3423F);
    EXPECT_NEAR(v0.R(), 2.2, 0.001);
    EXPECT_NEAR(v0.G(), 3.8, 0.001);
    EXPECT_NEAR(v0.B(), 44.3423, 0.001);
    EXPECT_NEAR(v0.X(), 2.2, 0.001);
    EXPECT_NEAR(v0.Y(), 3.8, 0.001);
    EXPECT_NEAR(v0.Z(), 44.3423, 0.001);
    EXPECT_NEAR(v0[0], 2.2, 0.001);
    EXPECT_NEAR(v0[1], 3.8, 0.001);
    EXPECT_NEAR(v0[2], 44.3423, 0.001);
    EXPECT_NEAR(v0.Length(), 44.5592, 0.001);
    EXPECT_NEAR(v0.SquareLength(), 1985.52230464, 0.1);
}

class Vec3OperatorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        v1 = Vec3(2.3F, 3.8F, 4.4F);
        v2 = Vec3(34.5F, 234.F, 53.9F);
    }

    Vec3 v1, v2;
};

TEST_F(Vec3OperatorTest, OperatorAdd)
{
    Vec3 v0 = v1 + v2;
    EXPECT_NEAR(v0[0], 36.8, 0.001);
    EXPECT_NEAR(v0[1], 237.8, 0.001);
    EXPECT_NEAR(v0[2], 58.3, 0.001);
}

TEST_F(Vec3OperatorTest, OperatorSubtract)
{
    Vec3 v0 = v2 - v1;
    EXPECT_NEAR(v0[0], 32.2, 0.001);
    EXPECT_NEAR(v0[1], 230.2, 0.001);
    EXPECT_NEAR(v0[2], 49.5, 0.001);
}

TEST_F(Vec3OperatorTest, CompoundOperatorAdd)
{
    v1 += v2;
    EXPECT_NEAR(v1[0], 36.8, 0.001);
    EXPECT_NEAR(v1[1], 237.8, 0.001);
    EXPECT_NEAR(v1[2], 58.3, 0.001);
}

TEST_F(Vec3OperatorTest, CompoundOperatorSubtract)
{
    v1 -= v2;
    EXPECT_NEAR(v1[0], -32.2, 0.001);
    EXPECT_NEAR(v1[1], -230.2, 0.001);
    EXPECT_NEAR(v1[2], -49.5, 0.001);
}

TEST_F(Vec3OperatorTest, OperatorMultiplicationScalarL)
{
    Vec3 result = 1.2 * v1;
    EXPECT_NEAR(result[0], 2.76, 0.1);
    EXPECT_NEAR(result[1], 4.56, 0.1);
    EXPECT_NEAR(result[2], 5.28, 0.1);
}

TEST_F(Vec3OperatorTest, OperatorMultiplicationScalarR)
{
    Vec3 result = v1 * 3;
    EXPECT_NEAR(result[0], 6.9, 0.1);
    EXPECT_NEAR(result[1], 11.4, 0.1);
    EXPECT_NEAR(result[2], 13.2, 0.1);
}

TEST_F(Vec3OperatorTest, OperatorMultiplicationVec3)
{
    Vec3 v3 = v1 * v2;
    EXPECT_NEAR(v3[0], 79.35, 0.1);
    EXPECT_NEAR(v3[1], 889.2, 0.1);
    EXPECT_NEAR(v3[2], 237.16, 0.1);
}

TEST_F(Vec3OperatorTest, CompoundOperatorMultiplicationScalar)
{
    v1 *= 2.3;
    EXPECT_NEAR(v1[0], 5.29, 0.1);
    EXPECT_NEAR(v1[1], 8.74, 0.1);
    EXPECT_NEAR(v1[2], 10.12, 0.1);
}

TEST_F(Vec3OperatorTest, CompoundOperatorMultiplicationVec3)
{
    v1 *= v2;
    EXPECT_NEAR(v1[0], 79.35, 0.1);
    EXPECT_NEAR(v1[1], 889.2, 0.1);
    EXPECT_NEAR(v1[2], 237.16, 0.1);
}

TEST_F(Vec3OperatorTest, CompoundOperatorDivisionScalar)
{
    v1 /= 9.8;
    EXPECT_NEAR(v1[0], 0.23469388, 0.1);
    EXPECT_NEAR(v1[1], 0.3877551, 0.1);
    EXPECT_NEAR(v1[2], 0.44897959, 0.1);
}

TEST_F(Vec3OperatorTest, CompoundOperatorDivisionVec3)
{
    v1 /= v2;
    EXPECT_NEAR(v1[0], 0.06666, 0.1);
    EXPECT_NEAR(v1[1], 0.016239, 0.1);
    EXPECT_NEAR(v1[2], 0.08163, 0.1);
}

TEST_F(Vec3OperatorTest, OperatorDivision)
{
    Vec3 v3 = v2 / v1;
    EXPECT_NEAR(v3[0], 15, 0.1);
    EXPECT_NEAR(v3[1], 61.578947, 0.1);
    EXPECT_NEAR(v3[2], 12.25, 0.1);
}

TEST(Vec3Test, UnitVector)
{
    Vec3 v(2, 3, 4);
    Vec3 unit_v = UnitVector(v);
    EXPECT_NEAR(unit_v[0], 0.424264, 0.1);
    EXPECT_NEAR(unit_v[1], 0.565685, 0.1);
    EXPECT_NEAR(unit_v[2], 0.707107, 0.1);
}

TEST(Vec3Test, VectorCross)
{
    Vec3 v1(2, 3, 4);
    Vec3 v2(3, 4, 5);
    Vec3 v3 = Cross(v1, v2);
    EXPECT_NEAR(v3[0], -1, 0.001);
    EXPECT_NEAR(v3[1], 2, 0.001);
    EXPECT_NEAR(v3[2], -1, 0.001);
}

TEST(Vec3Test, VectorDot)
{
    Vec3 v1(2, 3, 4);
    Vec3 v2(3, 4, 5);
    float result = Dot(v1, v2);
    EXPECT_NEAR(result, 38, 0.001);
}