#pragma once
#include "imgui.h"
#include "features/esp.hpp"
#include "features/aimbot.hpp"
#include "features/misc.hpp" // <-- Eklendi: Bhop, Mevlana ve Thirdperson için gerekli
#include <windows.h>

namespace Menu {
    // Menünün ilk açılışta doğrudan açık gelmesi için true
    inline bool MenuOpen = true;

    inline void Render() {
        // Insert tuşuna basıldığında açılıp kapanma (toggle) durumu
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            MenuOpen = !MenuOpen;
        }

        if (!MenuOpen) return;

        ImGui::Begin("Vsense v1.0 | CS2 Internal", &MenuOpen, ImGuiWindowFlags_AlwaysAutoResize);
        
        // 1. Visuals Sekmesi
        if (ImGui::CollapsingHeader("Visuals (ESP)", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::Checkbox("Box ESP", &Features::EspBox);
            ImGui::ColorEdit4("Box Rengi", Features::BoxColor);
        }

        // 2. Aimbot Sekmesi
        if (ImGui::CollapsingHeader("Aimbot", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::Checkbox("Aimbot Aktif", &Features::AimbotEnabled);
            ImGui::SliderFloat("FOV", &Features::Fov, 1.0f, 30.0f);
            ImGui::SliderFloat("Smooth", &Features::Smooth, 1.0f, 20.0f);
        }

        // 3. Misc & Movement Sekmesi (YENİ EKLENENLER)
        if (ImGui::CollapsingHeader("Misc & Movement", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::Checkbox("Bunnyhop (Bhop)", &Features::BhopEnabled);
            ImGui::Checkbox("Mevlana (Spinbot)", &Features::MevlanaEnabled);
            ImGui::Checkbox("Thirdperson (3. Şahıs)", &Features::ThirdpersonEnabled);
        }

        ImGui::Spacing();
        ImGui::Text("Durum: Vsense Aktif (Insert = Menü)");
        ImGui::End();
    }
}
