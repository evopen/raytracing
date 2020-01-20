#include "metal.h"
#include "random.h"

namespace rt
{
    auto Metal::Scatter(
        const Ray& ray_in, const Vec3& hit_point, const Vec3& normal, Vec3* attenuation, Ray* ray_out) const -> bool
    {
        Vec3 reflect_direction = Reflect(UnitVector(ray_in.Direction()), normal);

        *ray_out     = Ray(hit_point, reflect_direction + fuzz_ * rt::random::RandomInUnitSphere());
        *attenuation = albedo_;
        return (Dot(reflect_direction, normal) > 0);
    }
}