#pragma once
#include "SDL.h"

namespace Log
{

void pr(const std::string& text);
void info(const std::string& title, const std::string& text);
void err(const std::string& title, const std::string& text);
void errSDL(const std::string& title, const std::string& text);
void except(const std::string& title, const std::string& text);

};
