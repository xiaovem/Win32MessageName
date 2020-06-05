#include <Windows.h>
#include "Win32MessageName.hpp"

LRESULT CALLBACK WndProc(HWND wnd, UINT mt, WPARAM w, LPARAM l);

int WINAPI WinMain(HINSTANCE ins, HINSTANCE, PSTR, int n)
{
    WNDCLASS wc = { 0 };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = ins;
    wc.hIcon = LoadIconA(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = "{3DBD7647-97BA-4124-AA30-33567A10314E}";
    RegisterClassA(&wc);
    HWND wnd = CreateWindowExA(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "Win32MessageName", WS_OVERLAPPEDWINDOW
        , CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, nullptr, nullptr, ins, nullptr);
    ShowWindow(wnd, n);
    UpdateWindow(wnd);

    MSG tMSG;
    while (GetMessageA(&tMSG, nullptr, 0, 0))
    {
        TranslateMessage(&tMSG);
        DispatchMessageA(&tMSG);
    }
}

LRESULT CALLBACK WndProc(HWND wnd, UINT mt, WPARAM w, LPARAM l)
{
    OutputDebugStringA(wmname(mt));
    OutputDebugStringA("\n");
    if (mt == WM_DESTROY)
    {
        PostQuitMessage(1);
        return 0;
    }
    return DefWindowProcA(wnd, mt, w, l);
}
