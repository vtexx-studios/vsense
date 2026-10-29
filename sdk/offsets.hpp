#pragma once
#include <cstddef>

namespace cs2_dumper::offsets::client_dll {
    inline constexpr std::ptrdiff_t dwEntityList = 0;
    inline constexpr std::ptrdiff_t dwLocalPlayerPawn = 0;
    inline constexpr std::ptrdiff_t dwViewMatrix = 0;
    inline constexpr std::ptrdiff_t dwViewAngles = 0;
    inline constexpr std::ptrdiff_t dwForceJump = 0;
}

namespace Offsets {
    inline constexpr std::ptrdiff_t& dwEntityList = cs2_dumper::offsets::client_dll::dwEntityList;
    inline constexpr std::ptrdiff_t& dwLocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
    inline constexpr std::ptrdiff_t& dwViewMatrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
    inline constexpr std::ptrdiff_t& dwViewAngles = cs2_dumper::offsets::client_dll::dwViewAngles;
    inline constexpr std::ptrdiff_t& dwForceJump = cs2_dumper::offsets::client_dll::dwForceJump;

    // Netvar / Schema Değerleri
    inline constexpr std::ptrdiff_t m_iHealth = 0x334;
    inline constexpr std::ptrdiff_t m_hPlayerPawn = 0x804;
    inline constexpr std::ptrdiff_t m_vOldOrigin = 0x1274;
    inline constexpr std::ptrdiff_t m_iTeamNum = 0x3CB;
    inline constexpr std::ptrdiff_t m_fFlags = 0x3EC;
}
