//
// Created by kyle on 2024/09/23.
//

#include <simple2d.h>

auto DrawCircle() -> void {
    S2D_DrawCircle(100, 100, 200, 100, 1, 1, 0, 1);
}


auto main(int argc, char *argv[]) -> int {
    S2D_Window *pWin = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &DrawCircle, S2D_RESIZABLE);
    S2D_Show(pWin);
    S2D_FreeWindow(pWin);
    return 0;
}
