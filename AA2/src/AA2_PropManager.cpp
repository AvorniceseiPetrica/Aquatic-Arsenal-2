#include "AA2_PropManager.h"

AA2_PropManager::AA2_PropManager()
{

}

AA2_PropManager::~AA2_PropManager()
{

}

void AA2_PropManager::AddProp(const char *texture_path, int x, int y)
{
    AA2_Prop *prop = new AA2_Prop(texture_path);
    prop->Init(x, y);
    props.push_back(prop);
}

void AA2_PropManager::RenderProps()
{
    for(auto i : props)
        i->Render();
}