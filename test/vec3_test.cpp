#include "vec3.hpp"

#include <gtest/gtest.h>

TEST(Vec3Test, ConstructorAndGetter)
{
    Vec3 v0(2.2, 3.8, 44.3423);
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