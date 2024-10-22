#include <wtypes.h>
#include "utility"
#include "vector"

namespace offsets {
    std::pair<DWORD, std::vector<DWORD>> Ammo(0x18AC00, {0x140});
    std::pair<DWORD, std::vector<DWORD>> Health(0x17E0A8, {0xEC});
}