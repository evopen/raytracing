#pragma once

#include <array>
#include <cmath>
#include <iostream>

class Vec3
{
public:
    Vec3() = default;

    Vec3(float e0, float e1, float e2);

    auto X() const -> float;
    auto Y() const -> float;
    auto Z() const -> float;
    auto R() const -> float;
    auto G() const -> float;
    auto B() const -> float;
    auto Length() const -> float;
    auto SquareLength() const -> float;

    auto operator[](int kI) const -> float;
    auto operator[](int kI) -> float&;
    auto operator+=(Vec3& v) -> Vec3&;
    auto operator-=(Vec3& v) -> Vec3&;
    auto operator*=(Vec3& v) -> Vec3&;
    auto operator*=(float t) -> Vec3&;
    auto operator/=(Vec3& v) -> Vec3&;
    auto operator/=(float t) -> Vec3&;

private:
    std::array<float, 3> e_;
};

auto operator+(const Vec3& v1, const Vec3& v2) -> Vec3;
auto operator+(const Vec3& v1, const float t) -> Vec3;
auto operator+(const float t, const Vec3& v1) -> Vec3;
auto operator-(const Vec3& v1, const Vec3& v2) -> Vec3;
auto operator*(const Vec3& v1, const Vec3& v2) -> Vec3;
auto operator*(float t, const Vec3& v) -> Vec3;
auto operator*(const Vec3& v, float t) -> Vec3;
auto operator/(const Vec3& v1, const Vec3& v2) -> Vec3;
auto operator/(const Vec3& v, float t) -> Vec3;
auto operator==(const Vec3& v1, const Vec3& v2) -> bool;
auto Dot(const Vec3& v1, const Vec3& v2) -> float;
auto Cross(const Vec3& v1, const Vec3& v2) -> Vec3;
auto UnitVector(const Vec3& v) -> Vec3;
