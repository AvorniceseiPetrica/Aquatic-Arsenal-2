#include <iostream>

#include "AA2_Game.h"
#include <unistd.h>

using namespace std;

int main()
{
    AA2_Game game;
    int FPS = 60;
    int frame_time = 1000 / FPS;

    system("clear");
    game.Init("AA2");

    while(game.IsRunning())
    {
        int current_frame_start = SDL_GetTicks();

        game.HandleEvents();
        game.Update();
        game.Render();

        int current_frame_end = SDL_GetTicks();
        int current_frame_time = current_frame_end - current_frame_start;

        if(current_frame_time < frame_time)
            SDL_Delay(frame_time - current_frame_time);
    }
}