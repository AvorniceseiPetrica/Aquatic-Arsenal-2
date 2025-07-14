#include "AA2_Entity.h"

AA2_Entity::AA2_Entity(SDL_FRect *p_data)
{
    if(p_data == nullptr)
        SDL_Log("\n\tAA2_Entity::AA2_Entity()\t<< Provided NULL for (SDL_FRect *p_data) >>\n\n");
    else
    {
        data = new SDL_FRect;
        data->w = p_data->w;
        data->h = p_data->h;
        data->x = p_data->x;
        data->y = p_data->y;
    }
}

AA2_Entity::~AA2_Entity()
{
    if(data != nullptr)
        delete data;
}