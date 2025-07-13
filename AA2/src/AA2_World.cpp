#include "AA2_World.h"

AA2_World::AA2_World(AA2_GraphicsContext *p_graphics_context)
{
    SDL_FRect dst = {
        .x = player_spawn_x,
        .y = player_spawn_y,
        .w = 128,
        .h = 128
    };

    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_World::AA2_World()\t<< Provided NULL for (AA2_GraphicsContext *p_graphics_context) >>\n\n");
    else
        graphics_context = p_graphics_context;

    map = new AA2_Map(graphics_context);
    player = new AA2_Player(graphics_context, &dst, map);
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
    player->Init("Assets/Tiles/red.png");
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