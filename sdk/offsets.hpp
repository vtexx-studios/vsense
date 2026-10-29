#pragma once
#include <cstddef>

// a2x dumper'ın standart namespace yapısı
namespace cs2_dumper::offsets::client_dll {
    inline std::ptrdiff_t dwEntityList = 0x1A28A40;
    inline std::ptrdiff_t dwLocalPlayerPawn = 0x1868358;
    inline std::ptrdiff_t dwViewMatrix = 0x1A99060;
    inline std::ptrdiff_t dwViewAngles = 0x1A63210;
    inline std::ptrdiff_t m_iHealth = 0x334;
    inline std::ptrdiff_t m_hPlayerPawn = 0x804;
    inline std::ptrdiff_t m_vOldOrigin = 0x1274;
    inline std::ptrdiff_t m_iTeamNum = 0x3CB;
}

// Bizim esp.hpp ve aimbot.hpp dosyalarımızın kullandığı "Offsets::" yapısı için köprü (Alias):
namespace Offsets {
    inline std::ptrdiff_t& dwEntityList = cs2_dumper::offsets::client_dll::dwEntityList;
    inline std::ptrdiff_t& dwLocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
    inline std::ptrdiff_t& dwViewMatrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
    inline std::ptrdiff_t& dwViewAngles = cs2_dumper::offsets::client_dll::dwViewAngles;
    inline std::ptrdiff_t& m_iHealth = cs2_dumper::offsets::client_dll::m_iHealth;
    inline std::ptrdiff_t& m_hPlayerPawn = cs2_dumper::offsets::client_dll::m_hPlayerPawn;
    inline std::ptrdiff_t& m_vOldOrigin = cs2_dumper::offsets::client_dll::m_vOldOrigin;
    inline std::ptrdiff_t& m_iTeamNum = cs2_dumper::offsets::client_dll::m_iTeamNum;
}
