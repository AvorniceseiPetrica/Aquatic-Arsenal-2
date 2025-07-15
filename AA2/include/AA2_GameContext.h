#pragma once

#include "AA2_Camera.h"

class AA2_GameContext{

    private:

        static AA2_Camera *camera;

    public:

        static void Init(SDL_Rect *p_target);
        static AA2_Camera* GetCamera();
};