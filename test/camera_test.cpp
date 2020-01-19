#include "camera.h"

#include <gtest/gtest.h>

TEST(CameraTest, Constructor)
{
    Camera cam;

    EXPECT_TRUE(cam.Origin() == Vec3(0, 0, 0));
    EXPECT_TRUE(cam.LowerLeftCorner() == Vec3(-2, -1, -1));
    EXPECT_TRUE(cam.Horizontal() == Vec3(4, 0, 0));
    EXPECT_TRUE(cam.Vertical() == Vec3(0, 2, 0));
}

TEST(CameraTest, GetRay)
{
    Camera cam;
    Ray r = cam.GetRay(0, 0);
    EXPECT_TRUE(r.Origin() == Vec3(0, 0, 0));
    EXPECT_TRUE(r.Direction() == Vec3(-2, -1, -1));

    r = cam.GetRay(0.5, 0.5);
    EXPECT_TRUE(r.Origin() == Vec3(0, 0, 0));
    EXPECT_TRUE(r.Direction() == Vec3(0, 0, -1));
}