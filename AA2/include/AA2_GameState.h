#pragma once

#include "AA2_State.h"
#include "AA2_World.h"

class AA2_GameState : public AA2_State{

    private:

        AA2_World world;

    public:

        void Init() override;
        void HandleEvents(SDL_Event *e) override;
        void Update() override;
        void Render() override;
};