#include "AA2_LevelManager.h"

#include "AA2_RefLinks.h"

AA2_LevelManager::AA2_LevelManager()
{
    
}

AA2_LevelManager::~AA2_LevelManager()
{
    for(int i = 0; i < LEVEL_COUNT; i++)
        delete levels[i];
}

void AA2_LevelManager::Init()
{
    levels[0] = new AA2_Level("Assets/Maps/map0.txt", "Assets/Backgrounds/background.png", {.x = 400, .y = 500});
    levels[1] = new AA2_Level("Assets/Maps/map1.txt", "Assets/Backgrounds/background.png", {.x = 0, .y = 200});

    SDL_Log("Loaded levels...\n");

    current_level = levels[0];
    current_level->Init();
    player.ChangeSpawn(current_level->GetPlayerSpawn());
    player.Init();
    AA2_RefLinks::GetCamera()->SetTarget(player.GetRect());
}

void AA2_LevelManager::Update()
{
    player.Update();
    AA2_RefLinks::GetCamera()->Update();
    if(player.GetRect()->x > MAP_WIDTH - TILE_WIDTH * 2)
        ChangeLevel(1);
}

void AA2_LevelManager::Render()
{
    current_level->Render();
    player.Render();
}

void AA2_LevelManager::ChangeLevel(int id)
{
    current_level = levels[id];
    current_level->Init();
    player.ChangeSpawn(current_level->GetPlayerSpawn());
    player.Init();
}