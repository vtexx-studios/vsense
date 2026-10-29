#pragma once
#include <cstddef>

namespace Offsets {
    inline std::ptrdiff_t dwEntityList = 0x1A28A40;
    inline std::ptrdiff_t dwLocalPlayerPawn = 0x1868358;
    inline std::ptrdiff_t dwViewMatrix = 0x1A99060;
    inline std::ptrdiff_t dwViewAngles = 0x1A63210; // Kamera açıları için gerekli offset

    inline std::ptrdiff_t m_iHealth = 0x334;
    inline std::ptrdiff_t m_hPlayerPawn = 0x804;
    inline std::ptrdiff_t m_vOldOrigin = 0x1274;
    inline std::ptrdiff_t m_iTeamNum = 0x3CB;
}
