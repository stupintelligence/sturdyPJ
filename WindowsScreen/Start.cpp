#include "pch.h"
#include "Start.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    Start gStart;

    gStart.Init();
    gStart.Run();
    gStart.Release();
    
}