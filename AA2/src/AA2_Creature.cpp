#include "AA2_Creature.h"

AA2_Creature::AA2_Creature(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data) : AA2_Entity(p_graphics_context, p_data)
{
    texture_loader = new AA2_TextureLoader(p_graphics_context);
}

AA2_Creature::~AA2_Creature()
{
    if(texture_loader != nullptr)
        delete texture_loader;
}