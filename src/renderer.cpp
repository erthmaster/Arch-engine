#include <iostream>
#include "renderer.hpp"
#include <SDL2/SDL.h>

class Renderer::Impl
{
    public:
        SDL_Renderer* sdlRenderer;
};

Renderer::Renderer(Window *window, int index, uint32_t flags)
: pImpl(std::make_unique<Impl>())
{
    pImpl->sdlRenderer = SDL_CreateRenderer((SDL_Window*)window->getSdlWin(), index, flags);
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(pImpl->sdlRenderer);
}

void Renderer::clear(){
    SDL_RenderClear(pImpl->sdlRenderer);
}

void Renderer::present(){
    SDL_RenderPresent(pImpl->sdlRenderer);
}

void Renderer::setDrawColor(Color color){
    SDL_SetRenderDrawColor(pImpl->sdlRenderer, color.r, color.g, color.b, color.a);
}

void Renderer::drawRect(const Rect rect){
    const SDL_FRect sdlRect = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRectF(pImpl->sdlRenderer, &sdlRect);
}

void Renderer::drawLine(const Point p0, const Point p1){
    SDL_RenderDrawLineF(pImpl->sdlRenderer, p0.x, p0.y, p1.x, p1.y);
}