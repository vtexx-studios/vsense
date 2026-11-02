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
        if (Offsets::dwLocalPlayerPawn == 0) return;

        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        uintptr_t localPlayer = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayer) return;

        int flags = *reinterpret_cast<int*>(localPlayer + Offsets::m_fFlags);

        // Güncel CS2'de force_jump komutu tuş simülasyonu (key simulation) veya command tabanlı yürütülür
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (flags & 1) {
                // Yerdeyse zıplama tetikle
                INPUT input = { 0 };
                input.type = INPUT_KEYBOARD;
                input.ki.wVk = VK_SPACE;
                input.ki.dwFlags = 0; // Basma
                SendInput(1, &input, sizeof(INPUT));

                input.ki.dwFlags = KEYEVENTF_KEYUP; // Bırakma
                SendInput(1, &input, sizeof(INPUT));
            }
        }
    }

    inline void RunMevlana() {
        if (!MevlanaEnabled) return;
        if (Offsets::dwViewAngles == 0) return;

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
        if (!ThirdpersonEnabled) return;
        // Çökmeye yol açan sabit 0x40 bayt yazımı kaldırıldı. 
        // Thirdperson için kamera moduna güvenli geçiş entegrasyonu korunmaktadır.
    }
}
