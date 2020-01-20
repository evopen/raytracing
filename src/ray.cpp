#include "ray.h"


Ray::Ray(const Vec3& origin, const Vec3& direction) : origin_(origin), direction_(direction)
{
}

auto Ray::Origin() const -> Vec3
{
    return origin_;
}

auto Ray::Direction() const -> Vec3
{
    return direction_;
}

auto Ray::PointAtParameter(float t) const -> Vec3
{
    return origin_ + t * direction_;
}

auto Reflect(const Vec3& v, const Vec3& n) -> Vec3
{
    return v - 2 * Dot(v, n) * n;
}
