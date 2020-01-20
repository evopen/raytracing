#pragma once

#include "ray.h"

namespace rt
{
    class Material
    {
    public:
        virtual bool Scatter(
            const Ray& ray_in, const Vec3& hit_point, const Vec3& normal, Vec3* attenuation, Ray* ray_out) const = 0;
    };
}
