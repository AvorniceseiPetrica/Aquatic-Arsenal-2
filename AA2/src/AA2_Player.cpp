#include "AA2_Player.h"

#include "AA2_RefLinks.h"
#include "AA2_TextureLoader.h"
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
    data.w = 150;
    data.h = 150;

    frames[0] = AA2_TextureLoader::LoadTexture("Assets/player1.png");
    frames[1] = AA2_TextureLoader::LoadTexture("Assets/player2.png");
    frames[2] = AA2_TextureLoader::LoadTexture("Assets/player3.png");
    frames[3] = AA2_TextureLoader::LoadTexture("Assets/player4.png");

    current_frame = 0;

    SDL_Log("Initialized player...\n");
}

void AA2_Player::Update()
{
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
    collision_left = CheckCollision(new_x, data.y) || CheckCollision(new_x, data.y + data.h - 1);
    collision_right = CheckCollision(new_x + data.w - 1 - 20, data.y) || CheckCollision(new_x + data.w - 1, data.y + data.h - 1);

    if(!collision_left && !collision_right)
        data.x = data.x + velocity_x;

    if(keystates[SDL_SCANCODE_SPACE] && on_ground == true)
    {
        on_ground = false;
        velocity_y -= jump_strength;
    }
    
    velocity_y += gravity;
    new_y = data.y + velocity_y;
    collision_top = CheckCollision(data.x, new_y) || CheckCollision(data.x + data.w - 1, new_y);
    collision_bottom = CheckCollision(data.x, new_y + data.h - 1) || CheckCollision(data.x + data.w - 1, new_y + data.h - 1);

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

    if (!collision_bottom && velocity_y > 0)
    {
        on_ground = false;
    }

    current_frame++;
    if(current_frame / 6 >= 4)
        current_frame = 0;
}

void AA2_Player::Render()
{
    SDL_Rect camera = AA2_RefLinks::GetCamera()->GetViewPort();
    SDL_FRect dst = {
        .x = (float)(data.x - camera.x),
        .y = (float)(data.y - camera.y),
        .w = (float)data.w,
        .h = (float)data.h
    };

    if(velocity_x == 0)
    {
        if(moving_right)
            SDL_RenderTexture(AA2_RefLinks::GetRenderer(), frames[1], nullptr, &dst);
        else
            SDL_RenderTextureRotated(AA2_RefLinks::GetRenderer(), frames[1], nullptr, &dst, 0, nullptr, SDL_FLIP_HORIZONTAL);
    }
    else 
        if(moving_right)
            SDL_RenderTexture(AA2_RefLinks::GetRenderer(), frames[current_frame / 6], nullptr, &dst);
        else
            SDL_RenderTextureRotated(AA2_RefLinks::GetRenderer(), frames[current_frame / 6], nullptr, &dst, 0, nullptr, SDL_FLIP_HORIZONTAL);
}

bool AA2_Player::CheckCollision(int x, int y)
{
    int tile_x = x / TILE_WIDTH;
    int tile_y = y / TILE_HEIGHT;
    //SDL_Log("x = %d, tile_x = %x | y = %d, tile_y = %d\n", x, tile_x, y, tile_y);
    int tile_id = AA2_RefLinks::GetMap()->GetTileId(tile_y, tile_x);

    if(AA2_RefLinks::GetMap()->IsTileSolid(tile_id))
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