#include <SDL3/SDL.h>

class AA2_Game{

    private:

        SDL_Window *window;
        SDL_Renderer *renderer;
        bool isRunning;

    public:

        AA2_Game();
        ~AA2_Game();
        void init(char* title, int width, int heigth);
        void update();
        void render();
        void handleEvents();
        bool checkIfRunning();
};