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
: impl_(std::make_unique<Impl>()) {}

Event::~Event() = default;

bool Event::poll()
{
    return impl_->pollEvent();
}

int Event::type() const
{
    return impl_->getEventType();
}