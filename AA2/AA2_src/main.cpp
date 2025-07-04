#include <iostream>
#include <SDL3/SDL.h>
#include "AA2_Game.h"

using namespace std;

int main()
{
    AA2_Game *game = new AA2_Game();
    
    // target frame-rate
    const int FPS = 60;
    // the time necessary for a single frame
    const int frameTime = 1000 / FPS;

    system("clear");
    game->init("AA2", 500, 500);

    while(game->checkIfRunning())
    {
        int currentFrameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        int currentFrameEnd = SDL_GetTicks();
        int currentFrameTime = currentFrameEnd - currentFrameStart;

        if(frameTime > currentFrameTime)
            SDL_Delay(frameTime - currentFrameTime);
    }

    delete game;
}