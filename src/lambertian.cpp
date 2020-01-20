#include "lambertian.h"

#include "random.h"
#include "ray.h"

auto rt::Lambertian::Scatter(const Ray& ray_in, const HitRecord& rec, Vec3* attenuation, Ray* ray_out) const -> bool
{
    Vec3 diffuse_direction = rec.p + rec.normal + rt::random::RandomInUnitSphere() - rec.p;

    *ray_out = Ray(rec.p, diffuse_direction);
    *attenuation = albedo_;
    return true;
}
