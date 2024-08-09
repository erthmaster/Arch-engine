#include "shapes.hpp"

namespace Draw
{

void rect(const Rect rect, const Color color)
{
    const SDL_FRect sdlRect = {rect.x, rect.y, rect.w, rect.h};
    SDL_SetRenderDrawColor(App::activeRender, color.r, color.g, color.b, color.a);
    SDL_RenderFillRectF(App::activeRender, &sdlRect);
}

void line(const Point p0, const Point p1, const Color color)
{
    SDL_SetRenderDrawColor(App::activeRender, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLineF(App::activeRender, p0.x, p0.y, p1.x, p1.y);
}

}