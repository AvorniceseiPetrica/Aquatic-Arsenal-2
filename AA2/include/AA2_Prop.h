#pragma once

#include <string>

#include "AA2_Drawable_Entity.h"

class AA2_Prop : public AA2_Drawable_Entity{

    protected:

        std::string texture_path;

    public:

        AA2_Prop(std::string texture_path);
        ~AA2_Prop();
        void Init(int x, int y);
        void Update();
        void Render();
};