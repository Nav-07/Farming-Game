#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

class Loader {
private:
    std::map<std::string, SDL_Texture*> mTextures;

    Loader() {}
    static Loader* mInstance;
public:
    static Loader* getInstance();
    void createTexture(std::string id, std::string file);
    void destroy();
    
    SDL_Texture* getTexture(std::string id);
};
