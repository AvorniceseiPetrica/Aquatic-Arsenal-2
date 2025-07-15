#include "AA2_World.h"
#include "AA2_GameContext.h"

AA2_World::AA2_World()
{
    SDL_Rect dst = {
        .x = player_spawn_x,
        .y = player_spawn_y,
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

    if(camera != nullptr)
        delete camera;
}

void AA2_World::Init()
{
    camera = AA2_GameContext::GetCamera();
    map->Init();
    map->LoadMap("Assets/Maps/Map.txt");
    map->PrintMapInfo();
    player->Init();
    camera->SetTarget(player->GetRect());
}

void AA2_World::Update()
{
    player->Update();
    camera->Update();
    camera->PrintInfo();
}

void AA2_World::Render()
{
    map->Render();
    player->Render();
}