#include <iostream>
#include <SDL3/SDL.h>
#include "AA2_Game.h"

using namespace std;

int main()
{
    char title[4] = "AA2";
    AA2_Game Game;
    
    Game.init(title, 500, 500);

    while(Game.checkIfRunning())
    {
        Game.handleEvents();
        Game.update();
        Game.render();
    }
}