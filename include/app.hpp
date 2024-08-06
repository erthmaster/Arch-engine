#pragma once
#include "SDL.h"

class App
{

    public:
        App(const int winWidth, const int screenHeight, char* winTitle);

        const int WIN_WIDTH;
        const int WIN_HEIGHT;
        char* WIN_TITLE;
};