#include <iostream>
#include <SDL3/SDL.h>
#include "AA2_GameWindow.h"
using namespace std;

int main()
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Failed to initialize video subsystem | SDL_GetError() = %s", SDL_GetError());
        exit(-1);
    }
    
    char title[4] = "AA2";
    AA2_GameWindow wnd(title, 500, 500);
    bool running = true;
    
    while(running)
    {
        SDL_Event e;
        
        while(SDL_PollEvent(&e))
            if(e.type == SDL_EVENT_QUIT)
            {
                cout<<"Requested to destroy window\n";
                running = false;
            }
    }
}