#include "AA2_LevelManager.h"
#include "AA2_GameContext.h"

AA2_LevelManager::AA2_LevelManager()
{
    
}

AA2_LevelManager::~AA2_LevelManager()
{
    
}

void AA2_LevelManager::Init()
{
    map.Init();
    map.LoadMap("Assets/Maps/Map.txt");
    map.PrintMapInfo();
    player.Init();
    AA2_GameContext::GetCamera()->SetTarget(player.GetRect());
    background = AA2_TextureLoader::LoadTexture("Assets/Backgrounds/background.png");
}

void AA2_LevelManager::Update()
{
    player.Update(&map);
    AA2_GameContext::GetCamera()->Update();
}

void AA2_LevelManager::Render()
{
    SDL_FRect dst = {
        .x = 0,
        .y = 0,
        .w = 1920,
        .h = 1080
    };
    SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), background, nullptr, &dst);
    map.Render();
    player.Render();
}