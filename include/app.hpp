#pragma once
#include "color.hpp"
#include "SDL.h"

class App
{

    public:
        App() = delete;
        static void init(const int _winWidth, const int _screenHeight, char* _winTitle);
        static void init(const int _winWidth, const int _winHeight, char* _winTitle, SDL_Color _bgColor);

        static SDL_Renderer* activeRender;
        static void setRenderer(SDL_Renderer* renderer);

        static int winWidth;
        static int winHeight;
        static char* winTitle;

        static Color bgColor;
};