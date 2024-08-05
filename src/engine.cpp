#include <algorithm>
#include <iostream>
#include "engine.hpp"
#include "logging.hpp"

// Engine::Engine(Node& coreNode)
// : coreNode(coreNode) {};

Engine::~Engine() {};

bool Engine::state() { return isRunning; }

void Engine::run(Node* coreNode)
{
    if(isRunning) return;
    isRunning = true;

    coreNode->name = "CORE_NODE";

    Log::info("ENGINE", "Inited!");
    std::cout << coreNode->size() << "\n";

    coreNode->mainInit();

    while (isRunning)
    {
        coreNode->mainUpdate();
    }
}
