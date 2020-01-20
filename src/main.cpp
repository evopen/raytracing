#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "random.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

auto RandomInUnitSphere() -> Vec3
{
    Vec3 random_vec(rt::random::RandomReal(-1., 1.), rt::random::RandomReal(-1., 1.), rt::random::RandomReal(-1., 1.));
    return UnitVector(random_vec);
}

auto Color(const Ray& ray, Hittable* hittable) -> Vec3
{
    HitRecord rec;

    if (hittable->Hit(ray, 0.001, std::numeric_limits<float>::max(), &rec))
    {
        Vec3 diffuse_direction = rec.p + rec.normal + RandomInUnitSphere() - rec.p;
        Ray diffuse_ray(rec.p, diffuse_direction);
        return 0.5 * Color(diffuse_ray, hittable);
    }
    Vec3 direction    = UnitVector(ray.Direction());
    float color_ratio = 0.5 * (direction.Y() + 1.F);
    return color_ratio * Vec3(0.2, 0.2, 1) + (1 - color_ratio) * Vec3(1, 1, 1);
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
        fs.fill('0');

        const int kNx       = 800;  // width
        const int kNy       = 400;  // height
        const int kSamples  = 32;  // samples count
        const int kMaxColor = 255;

        fs << "P3\n" << kNx << ' ' << kNy << "\n255\n" << std::flush;
        int pos = fs.tellp();

        // initialize image with black
        for (int i = 0; i < kNy; i++)  // for every row
        {
            for (int j = 0; j < kNx; j++)  // for every column
            {
                fs << std::setw(3) << 0 << ' ' << std::setw(3) << 0 << ' ' << std::setw(3) << 0 << "\t";
            }
            fs << "\n";
        }
        fs.seekp(pos);
        fs.flush();


        Sphere small_sphere(Vec3(0, 0, -1), 0.5);
        Sphere big_sphere(Vec3(0, -100.5, -1), 100);

        std::vector<Hittable*> hittables;
        hittables.push_back(&small_sphere);
        hittables.push_back(&big_sphere);

        HittableList world(&hittables);

        Camera cam;

        float progress = 0;

        for (int i = kNy - 1; i >= 0; i--)  // for every row
        {
            for (int j = 0; j < kNx; j++)  // for every column
            {
                Vec3 col(0, 0, 0);
                for (int s = 0; s < kSamples; ++s)
                {
                    float u = ((float) j + rt::random::RandomReal(0.F, 1.F)) / kNx;
                    float v = ((float) i + rt::random::RandomReal(0.F, 1.F)) / kNy;

                    Ray r = cam.GetRay(u, v);
                    col += Color(r, &world);
                }
                col /= kSamples;
                col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

                int ir = static_cast<int>(col.R() * kMaxColor);
                int ig = static_cast<int>(col.G() * kMaxColor);
                int ib = static_cast<int>(col.B() * kMaxColor);
                fs << std::setw(3) << ir << ' ' << std::setw(3) << ig << ' ' << std::setw(3) << ib << "\t";
            }
            fs << "\n" << std::flush;
            if ((float) (kNy - i) / kNy > (progress + 0.05))
            {
                progress += 0.05;
                std::cout << progress * 100 << '%' << std::endl;
            }
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