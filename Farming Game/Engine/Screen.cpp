#include "Screen.hpp"

Screen* Screen::mInstance = nullptr;
Screen* Screen::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Screen();
    return mInstance;
}
void Screen::init(std::string title, unsigned int width, unsigned int height) {
    mTitle = title;
    mScreenWidth = width;
    mScreenHeight = height;
    
    mWindow = SDL_CreateWindow(mTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
    mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
    mIsOpen = true;
}
void Screen::destroy() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    delete mInstance;
}
void Screen::close() {
    mIsOpen = false;
}

void Screen::render(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(mRenderer, texture, &srcRect, &destRect, 0.0, nullptr, flip);
}

SDL_Window* Screen::getWindowContext() {
    return mWindow;
}
SDL_Renderer* Screen::getRenderingContext() {
    return mRenderer;
}
unsigned int Screen::getWindowWidth() {
    return mScreenWidth;
}
unsigned int Screen::getWindowHeight() {
    return mScreenHeight;
}
std::string Screen::getWindowTitle() {
    return mTitle;
}
bool Screen::isRunning() {
    return mIsOpen;
}

