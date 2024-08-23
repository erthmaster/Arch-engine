#include "window.hpp"
#include <SDL2/SDL.h>
#include "logging.hpp"
#include <string>
#include <iostream>
#include <memory>

class Window::Impl
{
    public:
        SDL_Window* sdlWin;
        Impl() : sdlWin(nullptr) {}

        ~Impl() {
            if (sdlWin)
                SDL_DestroyWindow(sdlWin);
        }
};

Window::Window(const char *title, int x, int y, int w, int h, uint32_t flags)
: pImpl(std::make_unique<Impl>())
{
    pImpl->sdlWin = SDL_CreateWindow(title, x, y, w, h, flags);
}  

void* Window::getSdlWin()
{
    return pImpl->sdlWin;
}

Window::~Window()
{
    SDL_DestroyWindow(pImpl->sdlWin);
}