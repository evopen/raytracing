#include "sphere.h"

#include <gtest/gtest.h>
TEST(SphereTest, Constructor)
{
    Sphere sphere(Vec3(2, 3, 4), 5);
    EXPECT_NEAR(sphere.Center().X(), 2, 0.001);
    EXPECT_NEAR(sphere.Center().Y(), 3, 0.001);
    EXPECT_NEAR(sphere.Center().Z(), 4, 0.001);
    EXPECT_NEAR(sphere.Radius(), 5, 0.001);

    sphere.SetCenter(Vec3(4, 5, 6));
    sphere.SetRadius(10);
    EXPECT_NEAR(sphere.Center().X(), 4, 0.001);
    EXPECT_NEAR(sphere.Center().Y(), 5, 0.001);
    EXPECT_NEAR(sphere.Center().Z(), 6, 0.001);
    EXPECT_NEAR(sphere.Radius(), 10, 0.001);
}

TEST(SphereTest, HitOuterSurface)
{
    HitRecord rec;
    Ray ray(Vec3(0, 0, 0), Vec3(1, 0, 0));
    Sphere sphere(Vec3(4, 0, 0), 1);
    EXPECT_TRUE(sphere.Hit(ray, 0, FLT_MAX, rec));
    EXPECT_NEAR(rec.normal[0], -1, 0.001);
    EXPECT_NEAR(rec.normal[1], 0, 0.001);
    EXPECT_NEAR(rec.normal[2], 0, 0.001);
    EXPECT_NEAR(rec.p[0], 3, 0.001);
    EXPECT_NEAR(rec.p[1], 0, 0.001);
    EXPECT_NEAR(rec.p[2], 0, 0.001);
    EXPECT_NEAR(rec.t, 3, 0.001);
}

TEST(SphereTest, HitInnerSurface)
{
    HitRecord rec;
    Ray ray(Vec3(0, 0, 0), Vec3(1, 0, 0));
    Sphere sphere(Vec3(1, 0, 0), 3);
    EXPECT_TRUE(sphere.Hit(ray, 0, FLT_MAX, rec));
    EXPECT_TRUE(rec.normal == Vec3(1, 0, 0));
    EXPECT_TRUE(rec.p == Vec3(4, 0, 0));
    EXPECT_NEAR(rec.t, 4, 0.001);
}

TEST(SphereTest, Miss)
{
    HitRecord rec;
    Ray ray1(Vec3(0, 0, 0), Vec3(1, 0, 0));
    Sphere sphere1(Vec3(-10, 0, 0), 3);
    EXPECT_FALSE(sphere1.Hit(ray1, 0, FLT_MAX, rec));
    Sphere sphere2(Vec3(0, 6, 0), 3);
    EXPECT_FALSE(sphere1.Hit(ray1, 0, FLT_MAX, rec));

    Ray ray2(Vec3(0, 0, 0), Vec3(0, 1, 0));
    Sphere sphere3(Vec3(4, 0, 0), 1);
    EXPECT_FALSE(sphere3.Hit(ray2, 0, FLT_MAX, rec));
    EXPECT_FALSE(sphere3.Hit(ray1, 0, 2, rec));
}