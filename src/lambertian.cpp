#include "lambertian.h"

#include "random.h"
#include "ray.h"

auto rt::Lambertian::Scatter(
    const Ray& ray_in, const Vec3& hit_point, const Vec3& normal, Vec3* attenuation, Ray* ray_out) const -> bool
{
    Vec3 diffuse_direction = hit_point + normal + rt::random::RandomInUnitSphere() - hit_point;

    *ray_out     = Ray(hit_point, diffuse_direction);
    *attenuation = albedo_;
    return true;
}
