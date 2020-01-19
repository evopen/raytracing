#include "vec3.h"

Vec3::Vec3(float e0, float e1, float e2) : e_{e0, e1, e2}
{
}

auto Vec3::X() const -> float
{
    return e_[0];
}
auto Vec3::Y() const -> float
{
    return e_[1];
}
auto Vec3::Z() const -> float
{
    return e_[2];
}
auto Vec3::R() const -> float
{
    return e_[0];
}
auto Vec3::G() const -> float
{
    return e_[1];
}
auto Vec3::B() const -> float
{
    return e_[2];
}

auto Vec3::operator+=(Vec3& v) -> Vec3&
{
    e_[0] += v[0];
    e_[1] += v[1];
    e_[2] += v[2];
    return *this;
}

auto Vec3::operator+=(Vec3&& v) -> Vec3&
{
    *this += v;
    return *this;
}

auto Vec3::operator-=(Vec3& v) -> Vec3&
{
    e_[0] -= v[0];
    e_[1] -= v[1];
    e_[2] -= v[2];
    return *this;
}

auto Vec3::operator*=(Vec3& v) -> Vec3&
{
    e_[0] *= v[0];
    e_[1] *= v[1];
    e_[2] *= v[2];
    return *this;
}

auto Vec3::operator*=(float t) -> Vec3&
{
    e_[0] *= t;
    e_[1] *= t;
    e_[2] *= t;
    return *this;
}

auto Vec3::operator/=(Vec3& v) -> Vec3&
{
    e_[0] /= v[0];
    e_[1] /= v[1];
    e_[2] /= v[2];
    return *this;
}

auto Vec3::operator/=(float t) -> Vec3&
{
    float k = 1 / t;
    e_[0] *= k;
    e_[1] *= k;
    e_[2] *= k;
    return *this;
}

auto Vec3::operator[](int i) const -> float
{
    return e_[i];
}
auto Vec3::operator[](int i) -> float&
{
    return e_[i];
}

auto Vec3::Length() const -> float
{
    return sqrt(SquareLength());
}
auto Vec3::SquareLength() const -> float
{
    return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2];
}

auto operator+(const Vec3& v1, const Vec3& v2) -> Vec3
{
    return Vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

auto operator+(const Vec3& v1, const float t) -> Vec3
{
    Vec3 v(v1[0] + t, v1[1] + t, v1[2] + t);
    return v;
}

auto operator+(const float t, const Vec3& v1) -> Vec3
{
    return v1 + t;
}

auto operator-(const Vec3& v1, const Vec3& v2) -> Vec3
{
    return Vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

auto operator*(const Vec3& v1, const Vec3& v2) -> Vec3
{
    return Vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

auto operator*(float t, const Vec3& v) -> Vec3
{
    return Vec3(t * v[0], t * v[1], t * v[2]);
}

auto operator*(const Vec3& v, float t) -> Vec3
{
    return Vec3(t * v[0], t * v[1], t * v[2]);
}

auto operator/(const Vec3& v1, const Vec3& v2) -> Vec3
{
    return Vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

auto operator/(const Vec3& v, float t) -> Vec3
{
    return Vec3(v[0] / t, v[1] / t, v[2] / t);
}

auto operator==(const Vec3& v1, const Vec3& v2) -> bool
{
    if (abs(v1[0] - v2[0]) < 0.0001 && abs(v1[1] - v2[1]) < 0.0001 && abs(v1[2] - v2[2]) < 0.0001)
    {
        return true;
    }
    else
    {
        return false;
    }
}


auto Dot(const Vec3& v1, const Vec3& v2) -> float
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

auto Cross(const Vec3& v1, const Vec3& v2) -> Vec3
{
    return Vec3(v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2], v1[0] * v2[1] - v1[1] * v2[0]);
}

auto UnitVector(const Vec3& v) -> Vec3
{
    return v / v.Length();
}
