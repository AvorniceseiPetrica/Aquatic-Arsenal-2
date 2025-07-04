#include <iostream>
#include "AA2_Game.h"
#include "AA2_TextureLoader.h"
#include "AA2_TextureManager.h"

SDL_Texture *txt, *TXT;
SDL_FRect dstR, srcR;

SDL_Renderer* AA2_Game::gameRenderer = nullptr;

AA2_Game::AA2_Game()
{

}

AA2_Game::~AA2_Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gameRenderer); 
    SDL_Quit();
    SDL_Log("Game cleaned successfully. Stopping now\n");
}

void AA2_Game::init(const char* title, int width, int heigth)
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

    gameRenderer = SDL_CreateRenderer(window, nullptr);

    if(gameRenderer == nullptr)
    {
        SDL_Log("\n\t<< Could not create renderer >> | SDL_GetError() = %s\n\n", SDL_GetError());
        isRunning = false;
    }
    else
        SDL_Log("Renderer created successfully\n");
    
    AA2_TextureManager MNG;
    MNG.initTextures();

    txt = AA2_TextureLoader::loadTexture("AA2/Assets/aaa.jpeg", gameRenderer);
    dstR.h = 50;
    dstR.w = 50;
    dstR.x = 10;
    srcR.h = 100;
    srcR.w = 100;
    srcR.x = 100;
    srcR.y = 100;
    TXT = MNG.getTexture(0);
}

void AA2_Game::update()
{
    SDL_SetRenderDrawColor(gameRenderer, 25, 255, 255, 255);
    dstR.x += 1;
}

void AA2_Game::render()
{
    SDL_RenderClear(gameRenderer);
    SDL_RenderTexture(gameRenderer, txt, nullptr, &dstR);
    SDL_RenderTexture(gameRenderer, TXT, nullptr, &srcR);
    SDL_RenderPresent(gameRenderer);
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

SDL_Renderer* AA2_Game::getGameRenderer()
{
    return gameRenderer;
}