#include "AA2_RefLinks.h"

#include "AA2_Game.h"

SDL_Window *AA2_RefLinks::window = nullptr;
SDL_Renderer *AA2_RefLinks::renderer = nullptr;
AA2_Camera *AA2_RefLinks::camera = new AA2_Camera;
AA2_Map *AA2_RefLinks::map = nullptr;
AA2_Game *AA2_RefLinks::game = nullptr;

void AA2_RefLinks::Init_Graphics(SDL_Window *p_window, SDL_Renderer *p_renderer)
{
    if(p_window == nullptr)
        SDL_Log("\n\tAA2_GraphicsContext::Init()\t<< Provided NULL for (SDL_Window *p_window) >>\n\n");
    else
        window = p_window;

    if(p_renderer == nullptr)
        SDL_Log("\n\tAA2_GraphicsContext::Init()\t<< Provided NULL for (SDL_Renderer *p_renderer) >>\n\n");
    else
        renderer = p_renderer;

    SDL_Log("Initialized AA2_RefLinks... | renderer_name = %s | window_id = %d\n", SDL_GetRendererName(renderer), SDL_GetWindowID(window));
}

void AA2_RefLinks::SetCameraTarget(SDL_Rect *p_target)
{
    camera->SetTarget(p_target);
}

void AA2_RefLinks::SetMap(AA2_Map *p_map)
{
    if(p_map == nullptr)
        SDL_Log("\n\tAA2_RefLinks::SetMap()\t<<Provided NULL for (AA2_Map *p_map) >>\n\n");
    else
        map = p_map;
}

void AA2_RefLinks::SetGame(AA2_Game *p_game)
{
    if(p_game == nullptr)
        SDL_Log("\n\tAA2_RefLinks::SetGame()\t<< Provided NULL for (AA2_Game *p_game) >>\n\n");
    else
        game = p_game;
}

SDL_Renderer* AA2_RefLinks::GetRenderer()
{
    return renderer;
}

AA2_Camera* AA2_RefLinks::GetCamera()
{
    return camera;
}

AA2_Map* AA2_RefLinks::GetMap()
{
    return map;
}

AA2_Game* AA2_RefLinks::GetGame()
{
    return game;
}