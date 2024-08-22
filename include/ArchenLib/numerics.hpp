#pragma once

class Point
{
    public:
        float x;
        float y;
};

class Vector2
{
    public:
        Vector2(float x1, float y1, float x2, float y2);
        Vector2(Point start, Point end);

        float x1;
        float x2;
        float y1;
        float y2;
};

class Rect
{
    public:
        float x;
        float y;
        float w;
        float h;
};