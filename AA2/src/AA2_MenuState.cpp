#include "AA2_MenuState.h"
#include "AA2_GraphicsContext.h"
#include "AA2_TextureLoader.h"
#include <iostream>

void AA2_MenuState::Init()
{
    background_txt = AA2_TextureLoader::LoadTexture("Assets/Menu/main_menu.jpg");
    start_game_unpressed_txt = AA2_TextureLoader::LoadTexture("Assets/Menu/start_game_unpressed.png");
    start_game_pressed_txt = AA2_TextureLoader::LoadTexture("Assets/Menu/start_game_pressed.png");
    quit_game_unpressed_txt = AA2_TextureLoader::LoadTexture("Assets/Menu/quit_game_unpressed.png");
    quit_game_pressed_txt = AA2_TextureLoader::LoadTexture("Assets/Menu/quit_game_pressed.png");
}

void AA2_MenuState::HandleEvents(SDL_Event *e)
{
    if(e->type == SDL_EVENT_QUIT)
    {
        SDL_Log("User requested quitting...\n");
        exit(0);
    }
    else
    {
        if(e->key.key == SDLK_1)
            start_game = true;
        else
            start_game = false;

        if(e->key.key == SDLK_2)
            quit_game = true;
        else
            quit_game = false;
    }
}

void AA2_MenuState::Update()
{
    
}

void AA2_MenuState::Render()
{
    SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), background_txt, nullptr, &background_rect);
    
    if(start_game)
        SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), start_game_pressed_txt, nullptr, &start_game_rect);
    else
        SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), start_game_unpressed_txt, nullptr, &start_game_rect);
    
    if(quit_game)
        SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), quit_game_pressed_txt, nullptr, &quit_game_rect);
    else
        SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), quit_game_unpressed_txt, nullptr, &quit_game_rect);
}