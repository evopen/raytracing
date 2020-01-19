#include "camera.h"

auto Camera::GetRay(float u, float v) -> Ray
{
    return Ray(origin_, lower_left_corner_ + u * horizontal_ + v * vertical_);
}

