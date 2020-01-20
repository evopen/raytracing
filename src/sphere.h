#pragma once

#include "hittable.h"
#include "lambertian.h"
#include "material.h"

class Sphere : public Hittable
{
public:
    Sphere() = default;
    Sphere(Vec3 center, float radius)
        : center_(center), radius_(radius), material_(new rt::Lambertian(Vec3(0.5, 0.5, 0.5)))
    {
    }
    Sphere(Vec3 center, float radius, rt::Material* material) : center_(center), radius_(radius), material_(material) {}

    auto Hit(const Ray& ray, float t_min, float t_max, HitRecord* rec) const -> bool override;

    auto Center() -> Vec3 { return center_; }
    auto SetCenter(const Vec3& center) -> void { center_ = center; }
    auto Radius() -> float { return radius_; }
    auto SetRadius(float radius) -> void { radius_ = radius; }

private:
    Vec3 center_;
    float radius_;
    rt::Material* material_;
};