#include "AA2_Game.h"
#include "AA2_Map.h"
#include "AA2_Player.h"

#include <iostream>

AA2_Game::AA2_Game()
{
    graphics_context = new AA2_GraphicsContext;
}

AA2_Game::~AA2_Game()
{
    if(graphics_context != nullptr)
        delete graphics_context;

    if(world != nullptr)
        delete world;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned...\n");
}

void AA2_Game::Init(const char* title)
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("\n\tAA2_Game::Init()\t<< Could not initialize SDL_INIT_VIDEO >>\n\n");
        is_running = false;
    }
    else
    {
        SDL_Log("Initialized video subsystems...\n");
        is_running = true;
        window = SDL_CreateWindow(title, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

        if(window == nullptr)
        {
            SDL_Log("\n\tAA2_Game:Init()\t<< Could not create window >>\n\n");
            is_running = false;
        }
        else
            SDL_Log("Created window...\n");

        renderer = SDL_CreateRenderer(window, nullptr);
        
        if(renderer == nullptr)
        {
            SDL_Log("\n\tAA2_Game::Init()\t<< Could not create renderer >>\n\n");
            is_running = false;
        }
        else
            SDL_Log("Created renderer...\n");
    }

    graphics_context->Init(window, renderer);
    current_state = new AA2_GameState;
    current_state->Init();
}

void AA2_Game::Update()
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xaa, 0xbb, SDL_ALPHA_OPAQUE);
    current_state->Update();
}

void AA2_Game::Render()
{
    SDL_RenderClear(renderer);

    current_state->Render();    
    
    SDL_RenderPresent(renderer);
}

bool AA2_Game::IsRunning()
{
    return is_running;
}

void AA2_Game::HandleEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        current_state->HandleEvents(&e);
    }
}

void AA2_Game::ChangeState(AA2_State *new_state)
{
    if(new_state != nullptr)
    {    
        current_state = new_state;
        current_state->Init();
    }
}
