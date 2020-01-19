#include "sphere.h"

auto Sphere::Hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const -> bool
{
    // A(ray.Origin()): Ray Origin
    // B(ray.Direction()): Ray Direction
    // C(Origin()): Sphere Origin
    // R(Radius()): Sphere Radius

    // Ray Point At Parameter(ray.PointAtParameter(t) = A + t * B

    // yield Equation: dot(B, B) * t^2 + dot(A - C, B) * 2t + dot(A - C) - R^2 = 0
    // solve for t, coefficient for ray direction
    // which is distance from ray origin to hit point, measured in t * ray.direction

    // solve quadratic equation a * t^2 + b * 2t, + c = 0
    // a: dot(B, B)
    // b: dot(A - C, B)
    // c: dot(A - C) - R^2
    // discriminant = b^2 - 4ac;


    Vec3 oc = ray.Origin() - center_;  // a temp variable for frequently used A-C in formula
    float a = Dot(ray.Direction(), ray.Direction());
    float b = 2 * Dot(oc, ray.Direction());
    float c = Dot(oc, oc) - radius_ * radius_;

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        float t;

        // the smaller(closer) root(hit point)
        t = (-b - sqrt(discriminant)) / (2 * a);  
        if (t > t_min && t < t_max)
        {
            rec.t      = t;
            rec.p      = ray.PointAtParameter(t);
            rec.normal = (rec.p - center_) / radius_;
            return true;
        }

        // the larger(farther) root(hit point), 
        // this is for when the camera is in side the sphere 
        t = (-b + sqrt(discriminant)) / (2 * a);  
        if (t > t_min && t < t_max)
        {
            rec.t      = t;
            rec.p      = ray.PointAtParameter(t);
            rec.normal = (rec.p - center_) / radius_;
            return true;
        }
    }
    return false;
}
