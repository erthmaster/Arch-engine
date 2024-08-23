#include "event.hpp"
#include <SDL2/SDL.h>

class Event::Impl
{
    public:
        SDL_Event sdlEvent;

        bool pollEvent()
        {
            return SDL_PollEvent(&sdlEvent);
        }

        int getEventType() const
        {
            return sdlEvent.type;
        }
};

Event::Event()
: pImpl(std::make_unique<Impl>()) {}

Event::~Event() = default;

bool Event::poll()
{
    return pImpl->pollEvent();
}

int Event::type() const
{
    return pImpl->getEventType();
}