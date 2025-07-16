#pragma once

#include <SDL3/SDL.h>

class AA2_State{

    public:

        virtual ~AA2_State() = default;
        virtual void Init() = 0;
        virtual void HandleEvents(SDL_Event *e) = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};