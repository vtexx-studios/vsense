#pragma once
#include "../sdk/vector.hpp"
#include "../sdk/offsets.hpp"
#include <windows.h>

namespace Features {
    inline bool BhopEnabled = false;
    inline bool MevlanaEnabled = false;
    inline bool ThirdpersonEnabled = false;

    inline void RunBhop() {
        if (!BhopEnabled) return;
        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        uintptr_t localPlayer = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayer) return;

        int flags = *reinterpret_cast<int*>(localPlayer + Offsets::m_fFlags);
        uintptr_t forceJump = client + Offsets::dwForceJump;

        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (flags & 1) {
                *reinterpret_cast<int*>(forceJump) = 6;
            } else {
                *reinterpret_cast<int*>(forceJump) = 256;
            }
        }
    }

    inline void RunMevlana() {
        if (!MevlanaEnabled) return;
        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        Vector3* viewAngles = reinterpret_cast<Vector3*>(client + Offsets::dwViewAngles);
        if (viewAngles) {
            viewAngles->y += 45.0f;
            if (viewAngles->y > 180.0f) viewAngles->y -= 360.0f;
            if (viewAngles->y < -180.0f) viewAngles->y += 360.0f;
        }
    }

    inline void RunThirdperson() {
        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;
        uintptr_t localPlayer = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayer) return;

        int observerMode = ThirdpersonEnabled ? 1 : 0;
        *reinterpret_cast<int*>(localPlayer + 0x40) = observerMode;
    }
}
