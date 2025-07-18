#include "AA2_Level.h"

AA2_Level::AA2_Level(const char *p_map_path, const char *p_background_path)
{
    if(p_map_path == nullptr)
        SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_map_path) >>\n\n");
    else
        if(p_background_path == nullptr)
            SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_background_path) >>\n\n");
        else
        {
            map_path = p_map_path;
            background_path = p_background_path;
        }

}

AA2_Level::~AA2_Level()
{

}

void AA2_Level::Init()
{
    map.Init();
    map.LoadMap(map_path);
    background = AA2_TextureLoader::LoadTexture(background_path);
}

void AA2_Level::Update()
{

}

void AA2_Level::Render()
{
    SDL_FRect dst = {
        .x = 0,
        .y = 0,
        .w = 1920,
        .h = 1080
    };
    SDL_RenderTexture(AA2_GraphicsContext::GetRenderer(), background, nullptr, &dst);
    map.Render();
}

AA2_Map* AA2_Level::GetMap()
{
    return &map;
}