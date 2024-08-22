#include <iostream>
#include <logging.hpp>
#include <SDL2/SDL.h>
// #include <stdexcept>
// #include "fmt/core.h"


namespace Log
{

void pr(const std::string& text)
{
    std::cout << text << std::endl;
}

void info(const std::string& title, const std::string& text)
{
    std::cout << "[" << title << "] " << text << std::endl;
}

void err(const std::string& title, const std::string& text)
{
    std::cerr << "[" << title << "] " << text << std::endl;
}

void errSDL(const std::string& text)
{
    std::cerr << "[SDL] " << text << ": " << SDL_GetError() << std::endl;
}

void except(const std::string& title, const std::string& text)
{
    std::string message = "[" + title + "] " + text;
    std::cout << message << std::endl;
    throw std::runtime_error(message);
}



void pr(const char* text)
{
    std::cout << text << std::endl;
}

void info(const char* title, const char* text)
{
    std::cout << "[" << title << "] " << text << std::endl;
}

void err(const char* title, const char* text)
{
    std::cerr << "[" << title << "] " << text << std::endl;
}

void errSDL(const char* text)
{
    std::cerr << "[SDL] " << text << ": " << SDL_GetError() << std::endl;
}

// void except(const char* title, const char* text)
// {
//     std::cout << "[" + title + "] " + text << std::endl;
//     throw std::runtime_error(message);
// }

} 
