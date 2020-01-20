#pragma once

#include "material.h"
#include "ray.h"

struct HitRecord
{
    float t;  // coefficient to ray direction
    Vec3 p;  // hit point
    Vec3 normal;
    rt::Material* material;
};

class Hittable
{
public:
    virtual auto Hit(const Ray& ray, float t_min, float t_max, HitRecord* rec) const -> bool = 0;
};