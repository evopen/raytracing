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

    inline Vec3& operator+=(Vec3& v)
    {
        e_[0] += v[0];
        e_[1] += v[1];
        e_[2] += v[2];
        return *this;
    }

    inline Vec3& operator-=(Vec3& v)
    {
        e_[0] -= v[0];
        e_[1] -= v[1];
        e_[2] -= v[2];
        return *this;
    }

    inline Vec3& operator*=(Vec3& v)
    {
        e_[0] *= v[0];
        e_[1] *= v[1];
        e_[2] *= v[2];
        return *this;
    }

    inline Vec3& operator*=(float t)
    {
        e_[0] *= t;
        e_[1] *= t;
        e_[2] *= t;
        return *this;
    }

    inline Vec3& operator/=(Vec3& v)
    {
        e_[0] /= v[0];
        e_[1] /= v[1];
        e_[2] /= v[2];
        return *this;
    }

    inline Vec3& operator/=(float t)
    {
        float k = 1 / t;
        e_[0] *= t;
        e_[1] *= t;
        e_[2] *= t;
        return *this;
    }

    [[nodiscard]] inline auto Length() const -> float { return sqrt(SquareLength()); }
    [[nodiscard]] inline auto SquareLength() const -> float { return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]; }

private:
    std::array<float, 3> e_;
};

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

inline Vec3 operator*(float t, const Vec3& v)
{
    return Vec3(t * v[0], t * v[1], t * v[2]);
}

inline Vec3 operator*(const Vec3& v, float t)
{
    return Vec3(t * v[0], t * v[1], t * v[2]);
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline Vec3 operator/(const Vec3& v, const float t)
{
    return Vec3(v[0] / t, v[1] / t, v[2] / t);
}


inline float dot(const Vec3& v1, const Vec3& v2)
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] + v2[2];
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
}

inline Vec3 UnitVector(const Vec3& v)
{
    return v / v.Length();
}