#pragma once

#include "AA2_Drawable_Entity.h"

class AA2_Creature : public AA2_Drawable_Entity{

    protected:

        int hitpoints;

    public:

        AA2_Creature();
        ~AA2_Creature();
};