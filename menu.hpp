#pragma once
#include "imgui.h"
#include "features/esp.hpp"
#include "features/aimbot.hpp"

namespace Menu {
    inline bool MenuOpen = true;

    inline void Render() {
        // Sağ Shift yerine Insert tuşu (VK_INSERT) kullanıyoruz
        if (GetAsyncKeyState(VK_INSERT) & 1) MenuOpen = !MenuOpen;
        if (!MenuOpen) return;

        ImGui::Begin("Vsense v1.0 | CS2 Internal", &MenuOpen, ImGuiWindowFlags_AlwaysAutoResize);
        
        if (ImGui::CollapsingHeader("Visuals (ESP & Chams)", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::Checkbox("Box ESP", &Features::EspBox);
            ImGui::ColorEdit4("Box Rengi", Features::BoxColor);
            ImGui::Checkbox("Charms", &Features::CharmsEnabled);
        }

        if (ImGui::CollapsingHeader("Aimbot", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::Checkbox("Aimbot Aktif", &Features::AimbotEnabled);
            ImGui::SliderFloat("FOV", &Features::Fov, 1.0f, 30.0f);
            ImGui::SliderFloat("Smooth", &Features::Smooth, 1.0f, 20.0f);
        }

        ImGui::Text("Durum: Vsense Aktif");
        ImGui::End();
    }
}
