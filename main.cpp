// Libraries
#include "iostream"
#include "map"
// Header Files
#include "memory.h"
#include "offsets.h"

namespace settings {
    int ammo = 1337;
    int health = 1337;
}

int main() {
    HWND hWnd = FindWindowA("SDL_app", "AssaultCube"); 

    DWORD pid = 0;
    GetWindowThreadProcessId(hWnd, &pid);

    HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

    DWORD baseAddress = memory::GetModuleBaseAddress((TCHAR*)("ac_client.exe"), pid);

    DWORD ammoPointerAddress = memory::GetPointerAddress(hWnd, baseAddress, offsets::Ammo.first, offsets::Ammo.second);
    DWORD healthPointerAddress = memory::GetPointerAddress(hWnd, baseAddress, offsets::Health.first, offsets::Health.second);

    while (true)
    {
        WriteProcessMemory(pHandle, (LPVOID)(ammoPointerAddress), &settings::ammo, sizeof(settings::ammo), nullptr);
        WriteProcessMemory(pHandle, (LPVOID)(healthPointerAddress), &settings::health, sizeof(settings::health), nullptr);
    }

    CloseHandle(pHandle);

    return 0;
}