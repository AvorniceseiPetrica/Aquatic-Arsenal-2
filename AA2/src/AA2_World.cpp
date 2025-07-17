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
    background = AA2_TextureLoader::LoadTexture("Assets/Backgrounds/background.png");
}

void AA2_World::Update()
{
    player->Update();
    AA2_GameContext::GetCamera()->Update();
}

void AA2_World::Render()
{
    SDL_FRect dst = {
        .x = 0,
        .y = 0,
        .w = 1920,
        .h = 1080
    };
    SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), background, nullptr, &dst);
    map->Render();
    player->Render();
}