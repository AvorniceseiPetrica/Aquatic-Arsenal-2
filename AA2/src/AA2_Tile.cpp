#include "AA2_Tile.h"

AA2_Tile::AA2_Tile(int p_id, bool p_is_solid)
{
    if(p_id < 0)
        SDL_Log("\n\tAA2_Tile::AA2_Tile()\t<< Invalid tile id >>\n\n");
    else    
        id = p_id;
    
    is_solid = p_is_solid;
}

AA2_Tile::~AA2_Tile()
{
    if(texture != nullptr)
        SDL_DestroyTexture(texture);
}

void AA2_Tile::Render()
{

}

bool AA2_Tile::IsSolid()
{
    return is_solid;
}

void AA2_Tile::SetTexture(SDL_Texture *p_texture)
{
    if(p_texture == nullptr)
        SDL_Log("\n\tAA2_Tile::SetTexture()\t<< Provided NULL for (SDL_Texture *p_texture) >>\n\n");
    else
        texture = p_texture;
}