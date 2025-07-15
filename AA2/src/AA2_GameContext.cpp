#include "AA2_GameContext.h"

AA2_Camera *AA2_GameContext::camera = new AA2_Camera;

void AA2_GameContext::Init(SDL_Rect *p_target)
{
    camera->SetTarget(p_target);
}

AA2_Camera* AA2_GameContext::GetCamera()
{
    return camera;
}