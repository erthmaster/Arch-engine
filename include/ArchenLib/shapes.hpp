#pragma once
#include "color.hpp"
#include "numerics.hpp"
#include "shapes.hpp"
#include "app.hpp"

namespace Draw
{

void rect(const Rect rect, const Color color);
void line(const Point p0, const Point p1, const Color color);
// void polygon(const Vector2 v0, const Vector2 v1, const Color color);

}