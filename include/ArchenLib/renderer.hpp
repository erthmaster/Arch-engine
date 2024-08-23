#pragma once
#include <memory>
#include "window.hpp"
#include "numerics.hpp"
#include "color.hpp"

class Renderer
{
    class Impl;
    std::unique_ptr<Impl> pImpl;

    public:
        Renderer(Window *window, int index, uint32_t flags);
        ~Renderer();

        void clear();
        void present();
        void setDrawColor(Color color);

        void drawRect(const Rect rect);
        void drawLine(const Point p0, const Point p1);
};