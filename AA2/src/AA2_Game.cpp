#include "AA2_Game.h"

#include "AA2_GameState.h"
#include "AA2_MenuState.h"

#include <iostream>

AA2_Game::AA2_Game()
{
    current_state = new AA2_GameState;
}

AA2_Game::~AA2_Game()
{  
    if(current_state != nullptr)
        delete current_state;
    
    CleanSDL();
}

void AA2_Game::Init(const char* title)
{
    InitSDL(title);
    reflinks.Init_Graphics(window, renderer);
    current_state->Init();
}

void AA2_Game::InitSDL(const char* title)
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
}

void AA2_Game::CleanSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned...\n");
}

void AA2_Game::Update()
{
    //SDL_SetRenderDrawColor(renderer, 0xff, 0xaa, 0xbb, SDL_ALPHA_OPAQUE);
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
        if(e.key.key == SDLK_ESCAPE)
            ChangeState(new AA2_MenuState(this));
        else
            current_state->HandleEvents(&e);
    }
}

void AA2_Game::ChangeState(AA2_State *new_state)
{
    if(new_state == nullptr)
        SDL_Log("\n\tAA2_Game::ChangeState()\t<< Provided NULL for (AA2_State *new_state) >>\n\n");
    else
    {
        if(current_state != nullptr)
            delete current_state;

        current_state = new_state;
        current_state->Init();
    }
}
