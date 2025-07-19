#pragma once

#include "AA2_State.h"
#include "AA2_Config.h"

class AA2_MenuState : public AA2_State{

    private:

        bool red = false, green = false, blue = false;
        SDL_FRect background_rect = {
            .x = 0,
            .y = 0,
            .w = WINDOW_WIDTH,
            .h = WINDOW_HEIGHT
        } ;
        SDL_FRect start_game_rect = {
            .x = 960 - 200,
            .y = 200,
            .w = 400,
            .h = 200
        };
        SDL_FRect quit_game_rect = {
            .x = 960 - 200,
            .y = 500,
            .w = 400,
            .h = 200
        };
        SDL_Texture *background_txt = nullptr;
        SDL_Texture *start_game_unpressed_txt = nullptr;
        SDL_Texture *start_game_pressed_txt = nullptr;
        SDL_Texture *quit_game_unpressed_txt = nullptr;
        SDL_Texture *quit_game_pressed_txt = nullptr;
        bool start_game = false;
        bool quit_game = false;

    public:

        AA2_MenuState();
        void Init() override;
        void HandleEvents(SDL_Event *e) override;
        void Update() override;
        void Render() override;
};