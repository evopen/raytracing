#pragma once
#include "material.h"

namespace rt
{
    class Metal : public Material
    {
    public:
        Metal(const Vec3& albedo) : albedo_(albedo) {}
        auto Scatter(const Ray& ray_in, const HitRecord& rec, Vec3* attenuation, Ray* ray_out) const -> bool override;

    private:
        Vec3 albedo_;
    };
}