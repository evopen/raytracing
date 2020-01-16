#pragma once

#include <array>
#include <cmath>
#include <gsl/gsl>
#include <iostream>

class Vec3
{
public:
    Vec3() = default;

    Vec3(float e0, float e1, float e2) : e_{e0, e1, e2} {}

    [[nodiscard]] inline auto X() const -> float { return e_[0]; }
    [[nodiscard]] inline auto Y() const -> float { return e_[1]; }
    [[nodiscard]] inline auto Z() const -> float { return e_[2]; }
    [[nodiscard]] inline auto R() const -> float { return e_[0]; }
    [[nodiscard]] inline auto G() const -> float { return e_[1]; }
    [[nodiscard]] inline auto B() const -> float { return e_[2]; }

    inline auto operator[](const int kI) const -> float { return gsl::at(e_, kI); }
    inline auto operator[](const int kI) -> float& { return gsl::at(e_, kI); }

    [[nodiscard]] inline auto Length() const -> float { return sqrt(SquareLength()); }
    [[nodiscard]] inline auto SquareLength() const -> float { return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]; }

private:
    std::array<float, 3> e_;
};