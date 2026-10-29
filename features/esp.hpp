#pragma once
#include "imgui.h"
#include "../sdk/vector.hpp"
#include "../sdk/offsets.hpp"
#include <windows.h>

namespace Features {
    inline bool EspBox = true;
    inline float BoxColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

    inline void RenderESP() {
        if (!EspBox) return;

        // GÜVENLİK: Offsetler sıfırsa işlem yapmadan çık (çökme ve donmaları önler)
        if (Offsets::dwViewMatrix == 0 || Offsets::dwEntityList == 0 || Offsets::dwLocalPlayerPawn == 0) return;

        uintptr_t client = (uintptr_t)GetModuleHandleA("client.dll");
        if (!client) return;

        float* viewMatrix = reinterpret_cast<float*>(client + Offsets::dwViewMatrix);
        if (!viewMatrix) return;

        uintptr_t entityList = *reinterpret_cast<uintptr_t*>(client + Offsets::dwEntityList);
        if (!entityList) return;

        uintptr_t localPlayerPawn = *reinterpret_cast<uintptr_t*>(client + Offsets::dwLocalPlayerPawn);
        if (!localPlayerPawn) return;

        int localTeam = *reinterpret_cast<int*>(localPlayerPawn + Offsets::m_iTeamNum);

        ImGuiWindowFlags flags = ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs;
        ImGui::Begin("ESP Overlay", nullptr, flags);
        ImGui::SetWindowSize(ImGui::GetIO().DisplaySize);
        ImVec2 screenSize = ImGui::GetIO().DisplaySize;

        for (int i = 0; i < 64; i++) {
            uintptr_t listEntry = *reinterpret_cast<uintptr_t*>(entityList + 0x8 * ((i & 0x7FFF) >> 9) + 16);
            if (!listEntry) continue;

            uintptr_t playerController = *reinterpret_cast<uintptr_t*>(listEntry + 120 * (i & 0x1FF));
            if (!playerController) continue;

            uint32_t pawnHandle = *reinterpret_cast<uint32_t*>(playerController + Offsets::m_hPlayerPawn);
            if (!pawnHandle) continue;

            uintptr_t listEntry2 = *reinterpret_cast<uintptr_t*>(entityList + 0x8 * ((pawnHandle & 0x7FFF) >> 9) + 16);
            if (!listEntry2) continue;

            uintptr_t pPawn = *reinterpret_cast<uintptr_t*>(listEntry2 + 120 * (pawnHandle & 0x1FF));
            if (!pPawn || pPawn == localPlayerPawn) continue;

            int health = *reinterpret_cast<int*>(pPawn + Offsets::m_iHealth);
            if (health <= 0 || health > 100) continue;

            int team = *reinterpret_cast<int*>(pPawn + Offsets::m_iTeamNum);
            if (team == localTeam) continue;

            Vector3 origin = *reinterpret_cast<Vector3*>(pPawn + Offsets::m_vOldOrigin);
            Vector2 screenCoords;

            if (WorldToScreen(origin, screenCoords, viewMatrix, (int)screenSize.x, (int)screenSize.y)) {
                ImGui::GetWindowDrawList()->AddRect(
                    ImVec2(screenCoords.x - 20, screenCoords.y - 50),
                    ImVec2(screenCoords.x + 20, screenCoords.y + 10),
                    ImGui::ColorConvertFloat4ToU32(ImVec4(BoxColor[0], BoxColor[1], BoxColor[2], BoxColor[3])),
                    0.0f, 0, 1.5f
                );
            }
        }
        ImGui::End();
    }
}
