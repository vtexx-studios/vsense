#pragma once
#include <cstddef>
#include <cstdint>

namespace cs2_dumper::offsets::client_dll {
    inline constexpr std::ptrdiff_t dwEntityList = 0x271EB08;
    inline constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x25698C8;
    inline constexpr std::ptrdiff_t dwViewMatrix = 0x256F1D0;
    inline constexpr std::ptrdiff_t dwViewAngles = 0x2580008;
}

namespace Offsets {
    inline constexpr std::ptrdiff_t& dwEntityList = cs2_dumper::offsets::client_dll::dwEntityList;
    inline constexpr std::ptrdiff_t& dwLocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
    inline constexpr std::ptrdiff_t& dwViewMatrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
    inline constexpr std::ptrdiff_t& dwViewAngles = cs2_dumper::offsets::client_dll::dwViewAngles;

    // Schema / Netvar Sabitleri
    inline constexpr std::ptrdiff_t m_iHealth = 0x334;
    inline constexpr std::ptrdiff_t m_hPlayerPawn = 0x804;
    inline constexpr std::ptrdiff_t m_vOldOrigin = 0x1274;
    inline constexpr std::ptrdiff_t m_iTeamNum = 0x3CB;
    inline constexpr std::ptrdiff_t m_fFlags = 0x3EC;
}
