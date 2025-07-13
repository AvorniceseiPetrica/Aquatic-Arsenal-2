#pragma once

#include "AA2_Entity.h"
#include "AA2_TextureLoader.h"

class AA2_Creature : public AA2_Entity{

    protected:

        SDL_Texture *texture = nullptr;
        AA2_TextureLoader *texture_loader = nullptr;

    public:

        AA2_Creature(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data);
        ~AA2_Creature() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};