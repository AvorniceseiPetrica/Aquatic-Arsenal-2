#pragma once

#include "AA2_Entity.h"
#include "AA2_TextureLoader.h"

class AA2_Creature : public AA2_Entity{

    protected:

        SDL_Texture *texture = nullptr;

    public:

        AA2_Creature();
        virtual ~AA2_Creature() = 0;
        virtual void Init(SDL_Rect *p_data);
        virtual void Update() = 0;
        virtual void Render() = 0;
};