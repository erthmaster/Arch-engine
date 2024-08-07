#include <iostream>
#include "engine.hpp"
#include "logging.hpp"

Engine::Engine(Node* coreNode, const float targetFps)
: CORE_NODE(coreNode), TARGET_FPS(targetFps) 
{
};

Engine::~Engine() {};

bool Engine::state() { return isRunning; }

bool Engine::setupSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        Log::errSDL("SDL", "SDL_Init Error");
        return false;
    }

    sdlWin = SDL_CreateWindow(App::winTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, App::winWidth, App::winHeight, SDL_WINDOW_SHOWN);
    if(sdlWin == nullptr) {
        Log::errSDL("SDL", "SDL_CreateWindow Error");
        SDL_Quit();
        return false;
    }

    App::activeRender = SDL_CreateRenderer(sdlWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(App::activeRender == nullptr) {
        Log::errSDL("SDL", "SDL_CreateRenderer Error");
        SDL_DestroyWindow(sdlWin);
        SDL_Quit();
        return false;
    }
    return true;
}

void Engine::run()
{
    if(isRunning) return; isRunning = true;

    if(!setupSDL())
        return;
    Log::info("ENGINE", "Inited!");

    const int frameDelay = 1000/TARGET_FPS;
    Uint32 frameStart;
    int frameTime;

    CORE_NODE->mainInit();
    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                
                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(App::activeRender, App::bgColor.r, App::bgColor.g, App::App::bgColor.b, 255);
        SDL_RenderClear(App::activeRender);

        // Update vvvv

        CORE_NODE->mainUpdate();

        // Update ^^^^

        SDL_RenderPresent(App::activeRender);
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    stop();
    return;
}

void Engine::stop()
{
    SDL_DestroyRenderer(App::activeRender);
    SDL_DestroyWindow(sdlWin);
    SDL_Quit();
    return;
}