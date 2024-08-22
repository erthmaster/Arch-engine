#include "window.hpp"
#include <SDL2/SDL.h>
#include "logging.hpp"
#include <string>

Window::Window()
: impl_(std::make_unique<Impl>()) {}

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

bool Window::create(const char *title, int x, int y, int w, int h, uint32_t flags)
{
    Log::pr("Program runs");
    impl_->sdlWin = SDL_CreateWindow(title, x, y, w, h, flags);
    Log::pr("Program runs");
    return true;
}  

void* Window::getSdlWin()
{
    return impl_->sdlWin;
}

Window::~Window()
{
    SDL_DestroyWindow(impl_->sdlWin);
}