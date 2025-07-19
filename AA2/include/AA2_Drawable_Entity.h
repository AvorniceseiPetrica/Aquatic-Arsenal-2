#pragma once

#include "AA2_Entity.h"

class AA2_Drawable_Entity : public AA2_Entity{

    protected:

        SDL_Texture *texture = nullptr;

    public:

        AA2_Drawable_Entity();
        ~AA2_Drawable_Entity();
};