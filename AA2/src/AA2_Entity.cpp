#include "AA2_Entity.h"

AA2_Entity::AA2_Entity()
{
        data = new SDL_Rect;
        data->w = 0;
        data->h = 0;
        data->x = 0;
        data->y = 0;    
}

AA2_Entity::~AA2_Entity()
{
    if(data != nullptr)
        delete data;
}

void AA2_Entity::Init(SDL_Rect *p_data)
{
    if(p_data == nullptr)
        SDL_Log("\n\tAA2_Entity::Init()\t<< Provided NULL for (SDL_Rect *p_data) >>\n\n");
    else
    {
        data->x = p_data->x;
        data->y = p_data->y;
        data->w = p_data->w;
        data->h = p_data->h;
    }
}