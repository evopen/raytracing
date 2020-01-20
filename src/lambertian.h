#pragma once

#include "material.h"

namespace rt
{
    class Lambertian : public Material
    {
    public:
        Lambertian(const Vec3& albedo) : albedo_(albedo) {}
        bool Scatter(const Ray& ray_in, const Vec3& hit_point, const Vec3& normal, Vec3* attenuation,
            Ray* ray_out) const override;

    private:
        Vec3 albedo_;
    };
}