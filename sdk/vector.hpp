#pragma once
#include <cmath>

struct Vector3 {
    float x, y, z;
    Vector3 operator-(const Vector3& o) const { return { x - o.x, y - o.y, z - o.z }; }
    Vector3 operator+(const Vector3& o) const { return { x + o.x, y + o.y, z + o.z }; }
    Vector3 operator*(float f) const { return { x * f, y * f, z * f }; }
    float Length() const { return sqrt(x * x + y * y + z * z); }
};

struct Vector2 {
    float x, y;
};

inline bool WorldToScreen(Vector3& pos, Vector2& screen, float* matrix, int width, int height) {
    float w = matrix[12] * pos.x + matrix[13] * pos.y + matrix[14] * pos.z + matrix[15];
    if (w < 0.01f) return false;

    float invw = 1.0f / w;
    float x = matrix[0] * pos.x + matrix[1] * pos.y + matrix[2] * pos.z + matrix[3];
    float y = matrix[4] * pos.x + matrix[5] * pos.y + matrix[6] * pos.z + matrix[7];

    screen.x = (width / 2.0f) + (0.5f * x * invw * width + 0.5f);
    screen.y = (height / 2.0f) - (0.5f * y * invw * height + 0.5f);
    return true;
}
