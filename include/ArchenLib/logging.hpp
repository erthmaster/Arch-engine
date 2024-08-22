#pragma once
#include <string>

namespace Log
{

void pr(const std::string& text);
void info(const std::string& title, const std::string& text);
void err(const std::string& title, const std::string& text);
void errSDL(const std::string& text);
// void except(const std::string& title, const std::string& text);

void pr(const char* text);
void info(const char* title, const char* text);
void err(const char* title, const char* text);
void errSDL(const char* text);
// void except(const char* title, const char* text);

};
