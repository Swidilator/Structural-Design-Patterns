// Taken directly from course, only edited to include namespace and switch Point from include to import.
#pragma once
#include <windows.h>

import bridge.Point;

namespace bridge
{
    class Window
    {
        HWND m_hWnd{};

    public:
        Window();
        void Show();
        static LRESULT CALLBACK CallBackHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        void DrawCircle(Point position, float radius);
        void DrawLine(Point start, Point end);
        void Run();
    };
}
