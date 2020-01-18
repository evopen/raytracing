#include "ray.h"

#include <gtest/gtest.h>

TEST(RayTest, Constructor)
{
    Ray ray(Vec3(1, 2, 3), Vec3(2, 3, -4));
    Vec3 origin    = ray.Origin();
    Vec3 direction = ray.Direction();
    EXPECT_NEAR(origin[0], 1, 0.001);
    EXPECT_NEAR(origin[1], 2, 0.001);
    EXPECT_NEAR(origin[2], 3, 0.001);
    EXPECT_NEAR(direction[0], 2, 0.001);
    EXPECT_NEAR(direction[1], 3, 0.001);
    EXPECT_NEAR(direction[2], -4, 0.001);
}

TEST(RayTest, PointAtParameter)
{
    Ray ray(Vec3(0, 0, 0), Vec3(2, 3, -4));
    Vec3 point = ray.PointAtParameter(3);
    EXPECT_NEAR(point[0], 2 * 3, 0.001);
    EXPECT_NEAR(point[1], 3 * 3, 0.001);
    EXPECT_NEAR(point[2], -4 * 3, 0.001);
}