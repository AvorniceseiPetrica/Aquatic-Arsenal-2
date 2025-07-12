#include "AA2_Game.h"
#include "AA2_Map.h"
#include <iostream>

AA2_Game::AA2_Game()
{
    graphics_context = new AA2_GraphicsContext;
    map = new AA2_Map(graphics_context);
}

AA2_Game::~AA2_Game()
{
    if(graphics_context != nullptr)
        delete graphics_context;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("Game cleaned...\n");
}

void AA2_Game::Init(const char* title)
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("\n\tAA2_Game::Init()\t<< Could not initialize SDL_INIT_VIDEO >>\n\n");
        is_running = false;
    }
    else
    {
        SDL_Log("Initialized video subsystems...\n");
        is_running = true;
        window = SDL_CreateWindow(title, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

        if(window == nullptr)
        {
            SDL_Log("\n\tAA2_Game:Init()\t<< Could not create window >>\n\n");
            is_running = false;
        }
        else
            SDL_Log("Created window...\n");

        renderer = SDL_CreateRenderer(window, nullptr);
        
        if(renderer == nullptr)
        {
            SDL_Log("\n\tAA2_Game::Init()\t<< Could not create renderer >>\n\n");
            is_running = false;
        }
        else
            SDL_Log("Created renderer...\n");
    }

    graphics_context->window = window;
    graphics_context->renderer = renderer;

    map->Init();
    map->PrintMapInfo();
    printf("\n");
    map->LoadMap("Assets/Maps/Map.txt");
    map->PrintMapInfo();
}

void AA2_Game::Update()
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xaa, 0xbb, SDL_ALPHA_OPAQUE);
}

void AA2_Game::Render()
{
    SDL_RenderClear(renderer);

    AA2_TextureLoader T(graphics_context);
    SDL_FRect dst;
    dst.h = 1080;
    dst.w = 1920;
    dst.x= 0;
    dst.y= 0;
    SDL_Texture *txt = T.LoadTexture("Assets/Backgrounds/background.png");
    SDL_RenderTexture(graphics_context->renderer, txt, nullptr, &dst);

    map->Render();
    
    SDL_RenderPresent(renderer);
}

bool AA2_Game::IsRunning()
{
    return is_running;
}

void AA2_Game::HandleEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_EVENT_QUIT)
        {
            SDL_Log("User requested quitting...\n");
            is_running = false;
        }
    }
}