#pragma once
#include "material.h"

namespace rt
{
    class Metal : public Material
    {
    public:
        Metal(const Vec3& albedo, float fuzz) : albedo_(albedo)
        {
            if (fuzz < 1)
            {
                fuzz_ = fuzz;
            }
            else
            {
                fuzz_ = 1;
            }
        }
        auto Scatter(const Ray& ray_in, const Vec3& hit_point, const Vec3& normal, Vec3* attenuation,
            Ray* ray_out) const -> bool override;

    private:
        Vec3 albedo_;
        float fuzz_;
    };
}