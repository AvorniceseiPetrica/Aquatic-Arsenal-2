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
    levels[0] = new AA2_Level("Assets/Maps/Map.txt", "Assets/Backgrounds/background.png");
    levels[1] = new AA2_Level("Assets/Maps/Map2.txt", "Assets/Backgrounds/background.png");
    current_level = levels[0];
    current_level->Init();
    player.Init();
    AA2_GameContext::GetCamera()->SetTarget(player.GetRect());
}

void AA2_LevelManager::Update()
{
    player.Update(current_level->GetMap());
    AA2_GameContext::GetCamera()->Update();
    // if(player.GetRect()->x > 500)
    //     ChangeLevel(1);
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
}