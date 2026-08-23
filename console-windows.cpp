#ifdef _WIN32

#include <cstdio>
#include <Windows.h>
bool initializeConsole()
{
    BOOL ok = AllocConsole();
    if ( ! ok)
        ok = AttachConsole(ATTACH_PARENT_PROCESS);
    if (ok)
        freopen("CONOUT$", "w", stdout);
    return ok;
}
static bool isConsoleAllocated = initializeConsole();

#endif
