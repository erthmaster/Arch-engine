#include "app.hpp"
#include "color.hpp"
#include <SDL2/SDL.h>
#include "node.hpp"

bool App::isRunning = false;
float App::maxFPS = 60.0f;
Event App::event;
Renderer* App::activeRender = nullptr;
Window* App::window = nullptr;
Node* App::coreNode = nullptr;
int App::winWidth = 800;
int App::winHeight = 600;
char* App::winTitle = const_cast<char*>("Archen game");
Color App::bgColor = LIGHT_GRAY;

void App::init(
                int _winWidth, 
                int _winHeight, 
                const char* _winTitle,
                float _maxFps,
                Color _bgColor, 
                Node* _coreNode,
                Renderer* _renderer
            )
{
    winWidth    = _winWidth;
    winHeight   = _winHeight;
    winTitle    = const_cast<char*>(_winTitle);
    bgColor     = _bgColor;
    maxFPS      = _maxFps;
    coreNode    = _coreNode;
}
