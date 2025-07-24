#pragma once

#include "AA2_Prop.h"

#include <vector>

class AA2_PropManager{

    private:

        std::vector<AA2_Prop*> props;

    public:

        AA2_PropManager();
        ~AA2_PropManager();
        void AddProp(const char *texture_path, int x, int y);
        void RenderProps();
};