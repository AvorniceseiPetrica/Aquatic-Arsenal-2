#include "AA2_Prop.h"

#include "AA2_TextureLoader.h"
#include "AA2_RefLinks.h"

AA2_Prop::AA2_Prop(std::string p_texture_path)
{
    texture_path = p_texture_path;
}

AA2_Prop::~AA2_Prop()
{

}

void AA2_Prop::Init(int x, int y)
{
    texture = AA2_TextureLoader::LoadTexture(texture_path.c_str());

    float txt_width, txt_height;

    SDL_GetTextureSize(texture, &txt_width, &txt_height);

    data.x = x;
    data.y = y;
    data.w = txt_width;
    data.h = txt_height;
}

void AA2_Prop::Update()
{

}

void AA2_Prop::Render()
{
    SDL_Rect camera = AA2_RefLinks::GetCamera()->GetViewPort();

    SDL_FRect rect = {
        .x = (float)data.x - camera.x,
        .y = (float)data.y - camera.y,
        .w = (float)data.w,
        .h = (float)data.h
    };

    SDL_RenderTexture(AA2_RefLinks::GetRenderer(), texture, nullptr, &rect);
}