#include "vec3.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

auto main() noexcept -> int
{
    try
    {
        std::cout << std::filesystem::current_path();
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
                Vec3 color(static_cast<float>(j) / kNx, static_cast<float>(i) / kNy, kBlueValue);
                int ir  = static_cast<int>(color.R() * kMaxColor);
                int ig  = static_cast<int>(color.G() * kMaxColor);
                int ib  = static_cast<int>(color.B() * kMaxColor);
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