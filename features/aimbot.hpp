#pragma once
#include "../sdk/vector.hpp"
#include "../sdk/offsets.hpp"
#include <windows.h>
#include <cmath>

namespace Features {
    inline bool AimbotEnabled = false;
    inline float Fov = 5.0f;
    inline float Smooth = 5.0f;

    inline void CalcAngle(const Vector3& src, const Vector3& dst, Vector3& angles) {
        Vector3 delta = src - dst;
        float hyp = sqrt(delta.x * delta.x + delta.y * delta.y);
        angles.x = atan2(delta.z, hyp) * (180.0f / 3.14159265358979323846f);
        angles.y = atan2(delta.y, delta.x) * (180.0f / 3.14159265358979323846f) + 180.0f;
        angles.z = 0.0f;
    }

    inline void RunAimbot() {
        if (!AimbotEnabled) return;
        if (!(GetAsyncKeyState(VK_RBUTTON) & 0x8000)) return;

        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        uintptr_t localPlayerPawn = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayerPawn) return;

        int localTeam = *reinterpret_cast<int*>(localPlayerPawn + Offsets::m_iTeamNum);
        Vector3 localEyePos = *reinterpret_cast<Vector3*>(localPlayerPawn + Offsets::m_vOldOrigin);
        Vector3 viewOffset = *reinterpret_cast<Vector3*>(localPlayerPawn + 0x318);
        localEyePos = localEyePos + viewOffset;

        uintptr_t entityList = *reinterpret_cast<uintptr_t*>(client + Offsets::dwEntityList);
        if (!entityList) return;

        float bestFov = Fov;
        Vector3 bestAngle = { 0, 0, 0 };
        bool targetFound = false;

        for (int i = 0; i < 64; i++) {
            uintptr_t listEntry = *reinterpret_cast<uintptr_t*>(entityList + 0x8 * ((i & 0x7FFF) >> 9) + 16);
            if (!listEntry) continue;

            uintptr_t playerController = *reinterpret_cast<uintptr_t*>(listEntry + 120 * (i & 0x1FF));
            if (!playerController) continue;

            int health = *reinterpret_cast<int*>(playerController + Offsets::m_iHealth);
            if (health <= 0 || health > 100) continue;

            uint32_t pawnHandle = *reinterpret_cast<uint32_t*>(playerController + Offsets::m_hPlayerPawn);
            if (!pawnHandle) continue;

            uintptr_t listEntry2 = *reinterpret_cast<uintptr_t*>(entityList + 0x8 * ((pawnHandle & 0x7FFF) >> 9) + 16);
            if (!listEntry2) continue;

            uintptr_t pPawn = *reinterpret_cast<uintptr_t*>(listEntry2 + 120 * (pawnHandle & 0x1FF));
            if (!pPawn || pPawn == localPlayerPawn) continue;

            int team = *reinterpret_cast<int*>(pPawn + Offsets::m_iTeamNum);
            if (team == localTeam) continue;

            Vector3 targetPos = *reinterpret_cast<Vector3*>(pPawn + Offsets::m_vOldOrigin);
            targetPos.z += 60.0f;

            Vector3 calculatedAngle;
            CalcAngle(localEyePos, targetPos, calculatedAngle);

            Vector3* viewAngles = reinterpret_cast<Vector3*>(client + Offsets::dwViewAngles);
            if (!viewAngles) continue;

            float fovDelta = sqrt(pow(calculatedAngle.x - viewAngles->x, 2) + pow(calculatedAngle.y - viewAngles->y, 2));
            if (fovDelta < bestFov) {
                bestFov = fovDelta;
                bestAngle = calculatedAngle;
                targetFound = true;
            }
        }

        if (targetFound) {
            Vector3* viewAngles = reinterpret_cast<Vector3*>(client + Offsets::dwViewAngles);
            if (viewAngles) {
                if (Smooth < 1.0f) Smooth = 1.0f;
                viewAngles->x += (bestAngle.x - viewAngles->x) / Smooth;
                viewAngles->y += (bestAngle.y - viewAngles->y) / Smooth;
            }
        }
    }
}
