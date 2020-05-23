#include "Loader.hpp"
#include "Screen.hpp"

Loader* Loader::mInstance = nullptr;
Loader* Loader::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Loader();
    return mInstance;
}
void Loader::createTexture(std::string id, std::string file) {
    SDL_Surface* textureSurface = IMG_Load(file.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Screen::getInstance()->getRenderingContext(), textureSurface);
    mTextures.insert({id,texture});
}
void Loader::destroy() {
    for (auto& texture : mTextures)
        SDL_DestroyTexture(texture.second);
    delete mInstance;
}
SDL_Texture* Loader::getTexture(std::string id) {
    return mTextures[id];
}
