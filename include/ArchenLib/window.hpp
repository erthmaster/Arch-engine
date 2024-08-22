#pragma once
#include <memory>

class Window
{
    class Impl;
    std::unique_ptr<Impl> impl_;
    void* getSdlWin();

    public:
        Window();
        bool create(const char *title, int x, int y, int w, int h, uint32_t flags);
        ~Window();

    friend class Renderer;
};