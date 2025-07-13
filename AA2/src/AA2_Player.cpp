#include "AA2_Player.h"
#include <iostream>

AA2_Player::AA2_Player(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data, AA2_Map *p_game_map) : AA2_Creature(p_graphics_context, p_data)
{
    if(p_game_map == nullptr)
        SDL_Log("\n\tAA2_Player::AA2_Player()\t<< Provided NULL for (AA2_Map *p_game_map) >>\n\n");
    else
        game_map = p_game_map;
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
    float new_x = data->x;;
    float new_y = data->y;
    bool collision_upper_left;
    bool collision_upper_right;
    bool collision_lower_left;
    bool collision_lower_right;

    if (keystates[SDL_SCANCODE_W]) new_y -= speed;
    if (keystates[SDL_SCANCODE_S]) new_y += speed;
    if (keystates[SDL_SCANCODE_A]) new_x -= speed;
    if (keystates[SDL_SCANCODE_D]) new_x += speed;

    collision_upper_left = CheckCollision(new_x, new_y);
    collision_lower_left = CheckCollision(new_x, new_y + height);
    collision_upper_right = CheckCollision(new_x + width, new_y);
    collision_lower_right = CheckCollision(new_x + width, new_y + height);

    if(
        !collision_lower_left &&
        !collision_lower_right &&
        !collision_upper_left &&
        !collision_upper_right
    )
    {
        data->x = new_x;
        data->y = new_y;
    }
}

void AA2_Player::Render()
{
    SDL_RenderTexture(graphics_context->renderer, texture, nullptr, data);
}

bool AA2_Player::CheckCollision(int x, int y)
{
    int tile_x = x / TILE_WIDTH;
    int tile_y = y / TILE_HEIGHT;
    int tile_id = game_map->GetTileId(tile_y, tile_x);

    if(game_map->IsTileSolid(tile_id))
        return true;
    
    return false;

}