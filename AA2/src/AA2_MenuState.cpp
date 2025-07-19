#include "AA2_MenuState.h"

#include "AA2_GameState.h"
#include "AA2_TextureLoader.h"
#include "AA2_Game.h"
#include <iostream>

AA2_MenuState::AA2_MenuState(AA2_Game *p_game_instance)
{
    if(p_game_instance == nullptr)
        SDL_Log("\n\tAA2_MenuState::AA2_MenuState()\t<< Provided NULL for (AA2_Game *p_game_instance) >>\n\n");
    else
        game_instance = p_game_instance;
}

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
    switch(e->type)
    {
        case SDL_EVENT_QUIT: {
            SDL_Log("User requested quitting...\n");
            exit(0);
        }
        break;

        case SDL_EVENT_KEY_DOWN: {
            if(e->key.key == SDLK_1)
                start_game = true;
            else
                start_game = false;

            if(e->key.key == SDLK_2)
                quit_game = true;
            else
                quit_game = false;

            if(e->key.key == SDLK_RETURN)
                game_instance->ChangeState(new AA2_GameState);
        }
        break;
    }
}

void AA2_MenuState::Update()
{
    
}

void AA2_MenuState::Render()
{
    SDL_RenderTexture(AA2_RefLinks::GetRenderer(), background_txt, nullptr, &background_rect);
    
    if(start_game)
        SDL_RenderTexture(AA2_RefLinks::GetRenderer(), start_game_pressed_txt, nullptr, &start_game_rect);
    else
        SDL_RenderTexture(AA2_RefLinks::GetRenderer(), start_game_unpressed_txt, nullptr, &start_game_rect);
    
    if(quit_game)
        SDL_RenderTexture(AA2_RefLinks::GetRenderer(), quit_game_pressed_txt, nullptr, &quit_game_rect);
    else
        SDL_RenderTexture(AA2_RefLinks::GetRenderer(), quit_game_unpressed_txt, nullptr, &quit_game_rect);
}