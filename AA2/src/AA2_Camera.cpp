#include "AA2_Camera.h"
#include "AA2_Config.h"

AA2_Camera::AA2_Camera()
{
    position = new SDL_Point;
    position->x = 0;
    position->y = 0;
}

AA2_Camera::~AA2_Camera()
{
    if(position != nullptr)
        delete position;
}

void AA2_Camera::SetTarget(SDL_Rect *p_target)
{
    if(p_target == nullptr)
        SDL_Log("\n\tAA2_Camera::SetTarget()\t<< Provided NULL for (SDL_FRect *p_target)\n\n");
    else
        target = p_target;
}

void AA2_Camera::Update()
{
    position->x = (target->x + target->w / 2) - WINDOW_WIDTH / 2;
    position->y = (target->y + target->h / 2) - WINDOW_HEIGHT / 2;

    if(position->x < 0)
        position->x = 0;

    if(position->y < 0)
        position->y = 0;

    if(position->x > MAP_WIDTH - WINDOW_WIDTH)
        position->x = MAP_WIDTH - WINDOW_WIDTH;
    
    if(position->y < MAP_HEIGHT - WINDOW_HEIGHT)
        position->y = MAP_HEIGHT - WINDOW_HEIGHT;
}

void AA2_Camera::PrintInfo()
{
    SDL_Log("X = %d | Y = %d\n", position->x, position->y);
}

SDL_Rect AA2_Camera::GetViewPort()
{
    return SDL_Rect {
        .x = position->x,
        .y = position->y,
        .w = WINDOW_WIDTH,
        .h = WINDOW_HEIGHT
    };
}