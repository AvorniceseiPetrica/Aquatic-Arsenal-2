#include "AA2_GameState.h"

#include <iostream>

void AA2_GameState::Init()
{
    level_manager.Init();
}

void AA2_GameState::HandleEvents(SDL_Event *e)
{
    if (e->type == SDL_EVENT_QUIT)
    {
        SDL_Log("User requested quitting...\n");
        exit(0);
    }
}

void AA2_GameState::Update()
{
    level_manager.Update();
}

void AA2_GameState::Render()
{
    level_manager.Render();
}