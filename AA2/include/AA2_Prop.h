#pragma once

#include "AA2_Drawable_Entity.h"

class AA2_Prop : public AA2_Drawable_Entity{

    protected:

        const char* texture_path;

    public:

        AA2_Prop(const char *texture_path);
        ~AA2_Prop();
        void Init(int x, int y);
        void Update();
        void Render();
};