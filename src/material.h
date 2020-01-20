#pragma once
#include "hittable.h"
#include "ray.h"

namespace rt
{
    class Material
    {
    public:
        virtual bool Scatter(const Ray& ray_in, const HitRecord& rec, Vec3* attenuation, Ray* ray_out) const = 0;
    };
}
