#include <iostream>
#include "engine.hpp"
#include "logging.hpp"
#include <SDL2/SDL.h>
#define LOG(x) std::cout << x << std::endl;

bool Engine::state() { return App::isRunning; }

bool Engine::setup()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        Log::errSDL("SDL_Init Error");
        return false;
    }

    if(!App::window->create(App::winTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, App::winWidth, App::winHeight, SDL_WINDOW_SHOWN));
    {
        Log::errSDL("SDL_CreateWindow Error");
        SDL_Quit();
        return false;
    }

    if(App::activeRender == nullptr)
        App::activeRender = new Renderer(App::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(App::activeRender == nullptr) {
        Log::errSDL("SDL_CreateRenderer Error");
        App::window->~Window();
        SDL_Quit();
        return false;
    }
    return true;
}

void Engine::run()
{
    if(App::isRunning) return; App::isRunning = true;

    if(!setup())
        return;
    Log::info("ENGINE", "Inited!");
    const int frameDelay = 1000/App::maxFPS;
    Uint32 frameStart;
    int frameTime;


    App::coreNode->mainInit();
    while (App::isRunning)
    {
        while(App::event.poll())
        {
            switch (App::event.type())
            {
                case SDL_QUIT:
                    App::isRunning = false;
                    break;
                
                default:
                    break;
            }
        }

        frameStart = SDL_GetTicks();
        App::activeRender->setDrawColor(App::bgColor);
        App::activeRender->clear();
        // Update vvvv

        App::coreNode->mainUpdate();

        // Update ^^^^
        App::activeRender->present();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    stop();
    return;
}

void Engine::stop()
{
    App::activeRender->~Renderer();
    App::window->~Window();
    SDL_Quit();
    return;
}