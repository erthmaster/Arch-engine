#pragma once
#include "core.hpp"
#include "node.hpp"

class Engine final
{
    bool isRunning = false;

    public:
        // Engine(Node& coreNode);
        ~Engine();
        bool state();
        void run(Node* coreNode);
};

