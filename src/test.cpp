#include <iostream>
#include "Archen.hpp"

void draw()
{
    Draw::rect((Rect){100,100,100,100}, (Color)RED);
    Draw::line({100, 100}, {200, 200}, BLUE);
}

int main(int argc, char *argv[])
{
    Node coreNode;

    coreNode.update.add(draw);

    App::init(800, 600, (char*)"Game", {255,255,255,0});
    Engine* engine = new Engine(&coreNode, 60);

    engine->run();

    return 0;
}