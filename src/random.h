#pragma once

#include "vec3.h"

#include <random>

namespace rt::random
{
    static std::random_device rd;
    static std::mt19937 mt(rd());

    template <typename T>
    inline auto RandomReal(T min, T max) -> decltype(auto)
    {
        std::uniform_real_distribution<T> distribution(min, max);
        auto rand_generator = [&]() -> T { return distribution(mt); };
        return rand_generator();
    }

    inline auto RandomInUnitSphere() -> Vec3
    {
        Vec3 random_vec(
            rt::random::RandomReal(-1., 1.), rt::random::RandomReal(-1., 1.), rt::random::RandomReal(-1., 1.));
        return UnitVector(random_vec);
    }
}