#pragma once
#include <memory>

class Window
{
    class Impl;
    std::unique_ptr<Impl> pImpl;
    void* getSdlWin();

    public:
        Window(const char *title, int x, int y, int w, int h, uint32_t flags);
        ~Window();

    friend class Renderer;
};