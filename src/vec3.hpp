#include <iostream>
#include <cmath>

class Vec3
{
public:
    Vec3() {}

    Vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

    [[nodiscard]] inline float X() const { return e[0]; }
    [[nodiscard]] inline float Y() const { return e[1]; }
    [[nodiscard]] inline float Z() const { return e[2]; }
    [[nodiscard]] inline float R() const { return e[0]; }
    [[nodiscard]] inline float G() const { return e[1]; }
    [[nodiscard]] inline float B() const { return e[2]; }

    inline float operator[](const int i) const { return e[i]; }
    inline float& operator[](const int i) { return e[i]; }

    inline float Length() const { return sqrt(SquareLength()); }
    inline float SquareLength() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    float e[3];
};