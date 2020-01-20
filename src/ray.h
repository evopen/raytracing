#pragma once

#include "vec3.h"

class Ray
{
public:
    Ray() = default;
    Ray(const Vec3& origin, const Vec3& direction);

    auto Origin() const -> Vec3;
    auto Direction() const -> Vec3;
    auto PointAtParameter(float t) const -> Vec3;

private:
    Vec3 origin_;
    Vec3 direction_;
};

auto Reflect(const Vec3& v, const Vec3& n) -> Vec3;