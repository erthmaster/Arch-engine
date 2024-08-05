#include <iostream>
#include <vector>

#include "logging.hpp"
#include "engine.hpp"
#include "node.hpp"

void hello()
{
    std::cout << "Hello World!" << std::endl;
}

void move()
{
    std::cout << "Moving!" << std::endl;
}

int main()
{
    Node core;
    Engine* engine = new Engine();

    Node scene;
    scene.name = "SCENE";
    
    Node gameObject;
    gameObject.name = "GAME_OBJECT";

    gameObject.init.add(hello);
    gameObject.update.add(move);

    gameObject.update.remove(0);

    scene.addNode(&gameObject);
    core.addNode(&scene);

    Log::pr(" Хуй" + gameObject.getParent()->name);

    engine->run(&core);

    return 0;
}