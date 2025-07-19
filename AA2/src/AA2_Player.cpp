#include "AA2_Player.h"
#include "AA2_GameContext.h"
#include <iostream>

AA2_Player::AA2_Player() : AA2_Creature()
{

}

AA2_Player::~AA2_Player()
{

}

void AA2_Player::Init()
{
    velocity_x = 0;
    velocity_y = 0;
    texture = AA2_TextureLoader::LoadTexture(texture_path);
    data.x = player_spawn.x;
    data.y = player_spawn.y;
    data.w = 128;
    data.h = 128;
}

void AA2_Player::Update(AA2_Map *p_map)
{
    if(p_map == nullptr)
        SDL_Log("\n\tAA2_Player::Update()\t<< Provided NULL for (AA2_Map *p_map) >>\n\n");

    const bool *keystates = SDL_GetKeyboardState(NULL);
    bool collision_top, collision_bottom, collision_left, collision_right;
    int new_x, new_y;

    velocity_x = 0;

    if (keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_D]) 
    {
        velocity_x = -speed;
        moving_right = false;
    }
    if (keystates[SDL_SCANCODE_D] && !keystates[SDL_SCANCODE_A]) 
    {
        velocity_x = +speed;
        moving_right = true;
    }

    new_x = data.x + velocity_x;
    collision_left = CheckCollision(p_map, new_x, data.y) || CheckCollision(p_map, new_x, data.y + data.h - 1);
    collision_right = CheckCollision(p_map, new_x + data.w - 1, data.y) || CheckCollision(p_map, new_x + data.w - 1, data.y + data.h - 1);

    if(!collision_left && !collision_right)
        data.x = data.x + velocity_x;

    if(keystates[SDL_SCANCODE_SPACE] && on_ground == true)
    {
        on_ground = false;
        velocity_y -= jump_strength;
    }
    
    velocity_y += gravity;
    new_y = data.y + velocity_y;
    collision_top = CheckCollision(p_map, data.x, new_y) || CheckCollision(p_map, data.x + data.w - 1, new_y);
    collision_bottom = CheckCollision(p_map, data.x, new_y + data.h - 1) || CheckCollision(p_map, data.x + data.w - 1, new_y + data.h - 1);

    if(!collision_top && !collision_bottom)
        data.y = data.y + velocity_y;
    else
    {
        if(collision_bottom)
        {
            on_ground = true;
            velocity_y = 0;
        }
        
        if(collision_top)
        {
            velocity_y = 0;
        }
    }
}

void AA2_Player::Render()
{
    SDL_Rect camera = AA2_GameContext::GetCamera()->GetViewPort();
    SDL_FRect dst = {
        .x = (float)(data.x - camera.x),
        .y = (float)(data.y - camera.y),
        .w = (float)data.w,
        .h = (float)data.h
    };
    SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), texture, nullptr, &dst);
}

bool AA2_Player::CheckCollision(AA2_Map *game_map, int x, int y)
{
    int tile_x = x / TILE_WIDTH;
    int tile_y = y / TILE_HEIGHT;
    //SDL_Log("x = %d, tile_x = %x | y = %d, tile_y = %d\n", x, tile_x, y, tile_y);
    int tile_id = game_map->GetTileId(tile_y, tile_x);

    if(game_map->IsTileSolid(tile_id))
        return true;
    
    return false;

}

SDL_Rect* AA2_Player::GetRect()
{
    return &data;
}

void AA2_Player::ChangeSpawn(SDL_Point new_spawn)
{
    player_spawn.x = new_spawn.x;
    player_spawn.y = new_spawn.y;
}

void AA2_Player::Update()
{
    
}