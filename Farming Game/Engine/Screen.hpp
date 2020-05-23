#include <SDL2/SDL.h>
#include <string>
#include <iostream>
using namespace std;

class Screen {
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    unsigned int mScreenWidth, mScreenHeight;
    std::string mTitle;
    bool mIsOpen;
    
    static Screen* mInstance;
    Screen() {  }
public:
    static Screen* getInstance();
    void init(std::string title, unsigned int width, unsigned int height);
    void destroy();
    void close();
    
    void render(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    SDL_Window* getWindowContext();
    SDL_Renderer* getRenderingContext();
    unsigned int getWindowWidth();
    unsigned int getWindowHeight();
    std::string getWindowTitle();
    bool isRunning();
};
