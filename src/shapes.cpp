#include "shapes.hpp"

namespace Draw
{

void rect(const Rect rect, const Color color)
{
    const SDL_Rect sdlRect = {rect.x, rect.y, rect.w, rect.h};
    SDL_SetRenderDrawColor(App::activeRender, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(App::activeRender, &sdlRect);
}

}