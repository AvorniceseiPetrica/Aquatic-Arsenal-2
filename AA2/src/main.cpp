#include <iostream>

#include "AA2_Game.h"
#include <unistd.h>

using namespace std;

int main()
{
    AA2_Game *game;

    game = new AA2_Game();
    system("clear");
    game->Init("AA2");

    while(game->IsRunning())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    delete game;
}