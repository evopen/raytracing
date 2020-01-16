#pragma once

#include <cmath>
#include <iostream>

class Vec3
{
public:
    Vec3() = default;

    Vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

    [[nodiscard]] inline auto X() const -> float { return e[0]; }
    [[nodiscard]] inline auto Y() const -> float { return e[1]; }
    [[nodiscard]] inline auto Z() const -> float { return e[2]; }
    [[nodiscard]] inline auto R() const -> float { return e[0]; }
    [[nodiscard]] inline auto G() const -> float { return e[1]; }
    [[nodiscard]] inline auto B() const -> float { return e[2]; }

    inline auto operator[](const int kI) const -> float { return e[kI]; }
    inline auto operator[](const int kI) -> float& { return e[kI]; }

    [[nodiscard]] inline auto Length() const -> float { return sqrt(SquareLength()); }
    [[nodiscard]] inline auto SquareLength() const -> float { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    float e[3]{};
};