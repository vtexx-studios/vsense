#pragma once
#include <cstddef>

namespace Offsets {
    // Client.dll statik offsetleri (Dumper burayı otomatik güncelleyecek)
    inline std::ptrdiff_t dwEntityList = 0x1A28A40; // Örnek/Güncel değerler
    inline std::ptrdiff_t dwLocalPlayerPawn = 0x1868358;
    inline std::ptrdiff_t dwViewMatrix = 0x1A99060;

    // Entity Schema / Netvar offsetleri
    inline std::ptrdiff_t m_iHealth = 0x334;
    inline std::ptrdiff_t m_hPlayerPawn = 0x804;
    inline std::ptrdiff_t m_vOldOrigin = 0x1274;
    inline std::ptrdiff_t m_iTeamNum = 0x3CB;
}
