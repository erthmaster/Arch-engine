#pragma once
#include "node.hpp"
#include "app.hpp"
#include "SDL.h"

class Engine final
{
    bool isRunning = false;
    SDL_Event event;

    SDL_Window* sdlWin;

    Node* CORE_NODE;

    bool setupSDL();

    public:
        const float TARGET_FPS;

        Engine(Node* coreNode, const float targetFps);
        ~Engine();

        bool state();
        void run();
        void stop();
};

