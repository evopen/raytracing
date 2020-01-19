#include "camera.h"

#include <gtest/gtest.h>

TEST(CameraTest, Constructor)
{
    Camera cam;

    EXPECT_TRUE(cam.Origin() == Vec3(0, 0, 0));
}