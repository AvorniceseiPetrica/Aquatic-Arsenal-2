#pragma once

#include <SDL3/SDL.h>
#include "AA2_Camera.h"
#include "AA2_Map.h"

class AA2_Game;

class AA2_RefLinks{

    private:

        static SDL_Window *window;
        static SDL_Renderer *renderer;
        static AA2_Camera *camera;
        static AA2_Map *map;
        static AA2_Game *game;

    public:

        static void Init_Graphics(SDL_Window *p_window, SDL_Renderer *p_renderer);
        static void SetCameraTarget(SDL_Rect *p_target);\
        static void SetMap(AA2_Map *p_map);
        static void SetGame(AA2_Game *p_game);
        static SDL_Renderer* GetRenderer();
        static AA2_Camera* GetCamera();
        static AA2_Map* GetMap();
        static AA2_Game* GetGame();
};