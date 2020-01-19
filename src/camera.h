#pragma once

#include "ray.h"
#include "vec3.h"

class Camera
{
public:
    Camera() : origin_(0, 0, 0), lower_left_corner_(-2, -1, -1), horizontal_(4, 0, 0), vertical_(0, 2, 0) {}
    auto Origin() -> Vec3 { return origin_; }
    auto LowerLeftCorner() -> Vec3 { return lower_left_corner_; }
    auto Horizontal() -> Vec3 { return horizontal_; }
    auto Vertical() -> Vec3 { return vertical_; }

    auto GetRay(float u, float v) -> Ray;

private:
    Vec3 origin_;
    Vec3 lower_left_corner_;
    Vec3 horizontal_;  // the horizontal span
    Vec3 vertical_;
};