#pragma once
#include "../sdk/vector.hpp"
#include "../sdk/offsets.hpp"

namespace Features {
    inline bool AimbotEnabled = true;
    inline float Fov = 5.0f;
    inline float Smooth = 5.0f;

    inline void RunAimbot() {
        if (!AimbotEnabled) return;
        // Aimbot hesaplama ve hedef odaklama döngüsü
    }
}
