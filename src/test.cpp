#include <iostream>
#include "Archen.hpp"

void hello()
{
    std::cout << "Hello World!" << std::endl;
}

void move()
{
    std::cout << "Moving!" << std::endl;
}

int main(int argc, char *argv[])
{
    Node core;

    App* app = new App(800, 600, (char*)"Game");
    Engine* engine = new Engine(app, &core, 60);

    engine->run();

    return 0;
}