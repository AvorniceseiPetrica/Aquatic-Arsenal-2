#include "AA2_World.h"
#include "AA2_GameContext.h"

AA2_World::AA2_World()
{
    map = new AA2_Map();
    player = new AA2_Player(map);
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
    player->Init();
    AA2_GameContext::GetCamera()->SetTarget(player->GetRect());
}

void AA2_World::Update()
{
    player->Update();
    AA2_GameContext::GetCamera()->Update();
}

void AA2_World::Render()
{
    map->Render();
    player->Render();
}