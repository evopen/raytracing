#include "metal.h"

namespace rt
{
    auto Metal::Scatter(const Ray& ray_in, const HitRecord& rec, Vec3* attenuation, Ray* ray_out) const -> bool
    {
        Vec3 reflect_direction = Reflect(ray_in.Direction(), rec.normal);

        *ray_out = Ray(rec.p, reflect_direction);
        *attenuation = albedo_;
        return (Dot(reflect_direction, rec.normal) > 0);
    }
}