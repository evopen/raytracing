#pragma once

#include "material.h"

namespace rt
{
    class Lambertian : public Material
    {
    public:
        Lambertian(const Vec3& albedo) : albedo_(albedo) {}
        auto Scatter(const Ray& ray_in, const HitRecord& rec, Vec3* attenuation, Ray* ray_out) const -> bool override;

    private:
        Vec3 albedo_;
    };
}