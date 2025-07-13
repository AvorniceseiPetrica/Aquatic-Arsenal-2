#include "AA2_Player.h"

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
    data->x += 0.1;
}

void AA2_Player::Render()
{
    SDL_RenderTexture(graphics_context->renderer, texture, nullptr, data);
}