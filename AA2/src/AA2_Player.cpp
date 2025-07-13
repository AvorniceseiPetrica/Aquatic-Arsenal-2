#include "AA2_Player.h"
#include <iostream>

AA2_Player::AA2_Player(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data) : AA2_Creature(p_graphics_context, p_data)
{

}

AA2_Player::~AA2_Player()
{

}

void AA2_Player::Init(const char *texture_path)
{
    texture = texture_loader->LoadTexture(texture_path);
}

void AA2_Player::Update()
{
    const bool *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_W]) data->y -= speed;
    if (keystates[SDL_SCANCODE_S]) data->y += speed;
    if (keystates[SDL_SCANCODE_A]) data->x -= speed;
    if (keystates[SDL_SCANCODE_D]) data->x += speed;
}

void AA2_Player::Render()
{
    SDL_RenderTexture(graphics_context->renderer, texture, nullptr, data);
}