#pragma once

#include <random>

namespace random
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
}