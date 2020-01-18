#include "hittable_list.h"
#include "sphere.h"

#include <gtest/gtest.h>

TEST(HittableListTest, Constructor)
{
    Hittable* sphere_1 = new Sphere(Vec3(0, 0, 0), 1);
    Hittable* sphere_2 = new Sphere(Vec3(2, 2, 3), 0.5);

    std::vector<Hittable*> hittables = {sphere_1, sphere_2};
    HittableList world(&hittables);

    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(0))->Center().X(), 0, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(0))->Center().Y(), 0, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(0))->Center().Z(), 0, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(0))->Radius(), 1, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(1))->Center().X(), 2, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(1))->Center().Y(), 2, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(1))->Center().Z(), 3, 0.001);
    EXPECT_NEAR(dynamic_cast<Sphere*>(world.List()->at(1))->Radius(), 0.5, 0.001);
}

TEST(HittableListTest, Hit)
{
    Hittable* sphere_1 = new Sphere(Vec3(3, 0, 0), 1);
    Hittable* sphere_2 = new Sphere(Vec3(10, 1, 1), 3);

    std::vector<Hittable*> hittables = {sphere_1, sphere_2};
    HittableList world(&hittables);

    HitRecord rec;
    Ray ray(Vec3(0, 0, 0), Vec3(1, 0, 0));

    EXPECT_TRUE(world.Hit(ray, 0, FLT_MAX, rec));
    EXPECT_NEAR(rec.normal[0], -1, 0.001);
    EXPECT_NEAR(rec.normal[1], 0, 0.001);
    EXPECT_NEAR(rec.normal[2], 0, 0.001);
    EXPECT_NEAR(rec.p[0], 2, 0.001);
    EXPECT_NEAR(rec.p[1], 0, 0.001);
    EXPECT_NEAR(rec.p[2], 0, 0.001);
    EXPECT_NEAR(rec.t, 2, 0.001);
}