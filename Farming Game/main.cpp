#include "Engine/Screen.hpp"
#include "Engine/Loader.hpp"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Screen::getInstance()->init("Farming Game", 640, 480);
    
    SDL_Event e;
    while (Screen::getInstance()->isRunning()) {
        SDL_PollEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
                Screen::getInstance()->close();
                break;
            default:
                break;
        }
    }
    
    Loader::getInstance()->destroy();
    Screen::getInstance()->destroy();
    return 0;
}
