#pragma once

#include "AA2_Entity.h"
#include "AA2_TextureLoader.h"

class AA2_Creature : public AA2_Entity{

    protected:

        SDL_Texture *texture = nullptr;

    public:

        AA2_Creature(SDL_Rect *p_data);
        ~AA2_Creature() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};