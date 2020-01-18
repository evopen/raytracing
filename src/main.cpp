#include "ray.h"
#include "vec3.h"

#include <filesystem>
#include <fstream>
#include <iostream>


// return the coefficient of ray direction to the hit point
auto HitSphere(const Vec3& center, const float kRadius, const Ray& ray) -> float
{
    float a = Dot(ray.Direction(), ray.Direction());
    float b = 2 * Dot(ray.Origin() - center, ray.Direction());
    float c = Dot(ray.Origin() - center, ray.Origin() - center) - kRadius * kRadius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        return -1;
    }
    else  // solve t in quadratic equation using quadratic formula
    {
        return (-b - sqrt(discriminant)) / (2 * a);
    }
}


auto Color(const Ray& ray) -> Vec3
{
    const Vec3 kSphereCenter  = Vec3(0, 0, -1);
    const float kSphereRadius = 0.5;
    float t                   = HitSphere(kSphereCenter, kSphereRadius, ray);
    if (t > 0)
    {
        Vec3 normal = UnitVector(ray.PointAtParameter(t) - kSphereCenter);
        return 0.5 * (normal + 1.f);
    }
    Vec3 direction    = UnitVector(ray.Direction());
    float color_ratio = 0.5 * (direction.Y() + 1.f);
    return color_ratio * Vec3(1, 0.2, 0.2) + (1 - color_ratio) * Vec3(1, 1, 1);
}

auto main() noexcept -> int
{
    try
    {
        Vec3 origin(0.F, 0.F, 0.F);
        Vec3 lower_left_corner(-2.f, -1.f, -1.f);
        Vec3 vertical(0, 2.f, 0);
        Vec3 horizontal(4.f, 0, 0);

        std::ofstream fs("result.ppm", std::fstream::out);
        if (!fs)
        {
            throw std::runtime_error("failed to open file");
        }

        const int kNx          = 200;  // width
        const int kNy          = 100;  // height
        const int kMaxColor    = 255;
        const float kBlueValue = 0.2F;

        fs << "P3\n" << kNx << ' ' << kNy << "\n255\n";
        for (int i = 0; i < kNy; i++)  // for every row
        {
            for (int j = 0; j < kNx; j++)  // for every column
            {
                float u = (float) j / kNx;
                float v = (float) i / kNy;
                Ray r(origin, Vec3(lower_left_corner + u * horizontal + v * vertical));
                Vec3 col = Color(r);
                int ir   = static_cast<int>(col.R() * kMaxColor);
                int ig   = static_cast<int>(col.G() * kMaxColor);
                int ib   = static_cast<int>(col.B() * kMaxColor);
                fs << ir << ' ' << ig << ' ' << ' ' << ib << "\t";
            }
            fs << "\n";
        }
        fs.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
    }

    return 0;
}