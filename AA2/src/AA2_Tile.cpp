#include "AA2_Tile.h"

AA2_Tile::AA2_Tile(int id, bool is_solid)
{
    if(id < 0)
        SDL_Log("\n\tAA2_Tile: << Invalid tile id (< 0) >>\n\n");
    else    
        this->id = id;
    
    this->is_solid = is_solid;
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