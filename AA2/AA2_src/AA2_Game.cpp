#include <iostream>
#include "AA2_Game.h"

AA2_Game::AA2_Game(char* title, int width, int heigth)
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("\t<< Could not initialize video subsystem >> | SDL_GetError() = %s\n", SDL_GetError());
        isRunning = false;
    }
    else
    {
        SDL_Log("Video subsystem initialized\n");
        isRunning = true;
    }
    
    window = SDL_CreateWindow(title, width, heigth, 0);

    if(window == nullptr)
    {
        SDL_Log("\t<< Could not create window >> | SDL_GetError() = %s\n", SDL_GetError());
        isRunning = false;
    }
    else
        SDL_Log("Created window successfully | Title: %s | Width: %d | Height: %d\n", title, width, heigth);

    renderer = SDL_CreateRenderer(window, nullptr);

    if(renderer == nullptr)
    {
        SDL_Log("\t<< Could not create renderer >> | SDL_GetError() = %s\n", SDL_GetError());
        isRunning = false;
    }
    else
        SDL_Log("Renderer created successfully\n");
}

AA2_Game::~AA2_Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    SDL_Log("Game cleaned successfully. Stopping now\n");
}

void AA2_Game::update()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void AA2_Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void AA2_Game::handleEvents()
{
    SDL_Event e;

    SDL_PollEvent(&e);

    switch(e.type)
    {
        case SDL_EVENT_QUIT: isRunning = false;
    }
}

bool AA2_Game::running()
{
    return isRunning;
}