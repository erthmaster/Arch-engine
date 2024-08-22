#include "shapes.hpp"
#include "numerics.hpp"
#include <SDL2/SDL.h>

namespace Draw
{

void rect(const Rect rect, const Color color)
{
    App::activeRender->setDrawColor(color);
    App::activeRender->drawRect(rect);
}

void line(const Point p0, const Point p1, const Color color)
{
    App::activeRender->setDrawColor(color);
    App::activeRender->drawLine(p0, p1);
}

// void polygon(const Point* points, const Color color)
// {
//     for (int i = 0; i < points; i++)
//     {
//         /* code */
//     }
    
//     SDL_SetRenderDrawColor(App::activeRender, color.r, color.g, color.b, color.a);
//     SDL_RenderDrawLines(App::activeRender);
// }

}