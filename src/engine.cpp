#include <iostream>
#include "engine.hpp"
#include "logging.hpp"

Engine::Engine(App* app, Node* coreNode, const float targetFps)
: app(app), CORE_NODE(coreNode), TARGET_FPS(targetFps) 
{
};

Engine::~Engine() {};

bool Engine::state() { return isRunning; }

void Engine::setupSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        Log::errSDL("SDL", "SDL_Init Error");
        return;
    }

    sdlWin = SDL_CreateWindow(app->WIN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, app->WIN_WIDTH, app->WIN_HEIGHT, SDL_WINDOW_SHOWN);
    if(sdlWin == nullptr) {
        Log::errSDL("SDL", "SDL_CreateWindow Error");
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(sdlWin, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        Log::errSDL("SDL", "SDL_CreateRenderer Error");
        SDL_DestroyWindow(sdlWin);
        SDL_Quit();
        return;
    }
}

void Engine::run()
{
    if(isRunning) return; isRunning = true;

    setupSDL();
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
            if(event.type == SDL_QUIT)
                isRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Update vvvv

        CORE_NODE->mainUpdate();

        // Update ^^^^

        SDL_RenderPresent(renderer);
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    stop();
}

void Engine::stop()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(sdlWin);
    SDL_Quit();
}