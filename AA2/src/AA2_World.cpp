#include "AA2_World.h"

AA2_World::AA2_World()
{
    SDL_FRect dst = {
        .x = player_spawn_x,
        .y = player_spawn_y,
        .w = 128,
        .h = 128
    };

    map = new AA2_Map();
    player = new AA2_Player(&dst, map);
}

AA2_World::~AA2_World()
{
    if(map != nullptr)
        delete map;

    if(player != nullptr)
        delete player;
}

void AA2_World::Init()
{
    map->Init();
    map->LoadMap("Assets/Maps/Map.txt");
    map->PrintMapInfo();
    player->Init(player_texture_path);
}

void AA2_World::Update()
{
    player->Update();
}

void AA2_World::Render()
{
    map->Render();
    player->Render();
}