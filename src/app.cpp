#include "app.hpp"
#include "color.hpp"

SDL_Renderer* App::activeRender = nullptr;
int App::winWidth = 0;
int App::winHeight = 0;
char* App::winTitle = nullptr;
Color App::bgColor = GRAY;

void App::init(const int _winWidth, const int _winHeight, char* _winTitle)
{
    winWidth = _winWidth;
    winHeight = _winHeight;
    winTitle = _winTitle;
    bgColor = GRAY;
}

void App::init(const int _winWidth, const int _winHeight, char* _winTitle, SDL_Color _bgColor)
{
    winWidth = _winWidth;
    winHeight = _winHeight;
    winTitle = _winTitle;
    bgColor = _bgColor;
}

void App::setRenderer(SDL_Renderer* renderer)
{
    activeRender = renderer;
}
