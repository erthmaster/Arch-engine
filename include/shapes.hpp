#pragma once
#include "SDL.h"
#include "color.hpp"
#include "numerics.hpp"
#include "shapes.hpp"
#include "app.hpp"

namespace Draw
{

void rect(const Rect rect, const Color color);
void line(const Point p0, const Point p1, const Color color);

}