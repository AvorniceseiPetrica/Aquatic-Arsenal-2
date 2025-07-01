#include "AA2_GameWindow.h"
#include <iostream>

AA2_GameWindow::AA2_GameWindow(char *title, int w, int h)
{
    wnd = SDL_CreateWindow(title, w, h, 0);

    if(wnd == nullptr)
    {
        SDL_Log("Could not create window | SDL_GetError() = %s", SDL_GetError());
        exit(-1);
    }
}