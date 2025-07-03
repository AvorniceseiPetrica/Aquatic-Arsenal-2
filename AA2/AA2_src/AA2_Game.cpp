#include <iostream>
#include "AA2_Game.h"
#include "AA2_TextureLoader.h"

SDL_Texture *txt;
SDL_FRect dstR, srcR;

AA2_Game::AA2_Game()
{
    
}

AA2_Game::~AA2_Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    SDL_Log("Game cleaned successfully. Stopping now\n");
}

void AA2_Game::init(char* title, int width, int heigth)
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("\n\t<< Could not initialize video subsystem >> | SDL_GetError() = %s\n\n", SDL_GetError());
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
        SDL_Log("\n\t<< Could not create window >> | SDL_GetError() = %s\n\n", SDL_GetError());
        isRunning = false;
    }
    else
        SDL_Log("Created window successfully | Title: %s | Width: %d | Height: %d\n", title, width, heigth);

    renderer = SDL_CreateRenderer(window, nullptr);

    if(renderer == nullptr)
    {
        SDL_Log("\n\t<< Could not create renderer >> | SDL_GetError() = %s\n\n", SDL_GetError());
        isRunning = false;
    }
    else
        SDL_Log("Renderer created successfully\n");

    
    txt = AA2_TextureLoader::loadTexture("AA2/Assets/aaa.jpeg", renderer);
    dstR.h = 50;
    dstR.w = 50;
    dstR.x = 10;
}

void AA2_Game::update()
{
    SDL_SetRenderDrawColor(renderer, 25, 255, 255, 255);
}

void AA2_Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, txt, nullptr, &dstR);
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

bool AA2_Game::checkIfRunning()
{
    return isRunning;
}