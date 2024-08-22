#include "numerics.hpp"
#include <SDL2/SDL.h>

Vector2::Vector2(float x1, float y1, float x2, float y2)
: x1(x1), x2(x2), y1(y1), y2(y2) 
{};

Vector2::Vector2(Point start, Point end)
: x1(start.x), x2(end.y), y1(start.y), y2(end.y) 
{};

// Point operator+ (Point v1, Point v2)
// {
    
// }