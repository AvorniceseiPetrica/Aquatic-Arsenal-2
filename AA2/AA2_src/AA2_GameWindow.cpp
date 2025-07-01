#include "AA2_GameWindow.h"

AA2_GameWindow::AA2_GameWindow(char *title, int w, int h)
{
    if(wnd == nullptr)
        wnd = SDL_CreateWindow(title, w, h, 0);
}