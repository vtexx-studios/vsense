#pragma once
#include "../sdk/vector.hpp"
#include "../sdk/offsets.hpp"
#include <windows.h>

namespace Features {
    inline bool AimbotEnabled = false;
    inline float Fov = 5.0f;
    inline float Smooth = 5.0f;

    inline void RunAimbot() {
        if (!AimbotEnabled) return;

        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        uintptr_t localPlayerPawn = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayerPawn) return;

        // Aimbot hedef arama ve açı hesaplama mantığı buraya eklenecektir.
    }
}
