#include <iostream>
#include <logging.hpp>
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

} 
