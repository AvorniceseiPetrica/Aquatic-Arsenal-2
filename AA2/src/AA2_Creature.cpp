#include "AA2_Creature.h"

AA2_Creature::AA2_Creature(SDL_FRect *p_data) : AA2_Entity(p_data)
{
    texture_loader = new AA2_TextureLoader();
}

AA2_Creature::~AA2_Creature()
{
    if(texture_loader != nullptr)
        delete texture_loader;
}