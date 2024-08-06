#pragma once
#include "node.hpp"
#include "app.hpp"
#include "SDL.h"

class Engine final
{
    bool isRunning = false;
    SDL_Event event;

    App* app;
    SDL_Window* sdlWin;
    SDL_Renderer* renderer;

    Node* CORE_NODE;

    void setupSDL();

    public:
        const float TARGET_FPS;

        Engine(App* app, Node* coreNode, const float targetFps);
        ~Engine();

        bool state();
        void run();
        void stop();
};

