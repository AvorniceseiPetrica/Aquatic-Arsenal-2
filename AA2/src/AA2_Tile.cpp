#include "AA2_Tile.h"

AA2_Tile::AA2_Tile(AA2_GraphicsContext *p_graphics_context, int p_id, bool p_is_solid)
{
    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_Tile::AA2_Tile()\t<< Provided NULL for (AA2_GraphicsContext *graphics_context) >>\n\n");
    else
        graphics_context = p_graphics_context;

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

void AA2_Tile::Render(float x, float y)
{
    SDL_FRect dst;

    if(texture == nullptr)
        SDL_Log("\n\tAA2_Tile::Render()\t<< NULL texture for tile %d >>", id);

    dst.h = TILE_HEIGHT;
    dst.w = TILE_WIDTH;
    dst.x = x;
    dst.y = y;
    SDL_RenderTexture(graphics_context->renderer, texture, nullptr, &dst);
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