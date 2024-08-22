#pragma once
#include "node.hpp"
#include "app.hpp"
#include "event.hpp"
#include "window.hpp"

class Engine final
{
    static bool setup();

    public:
        Engine() = delete;
        static bool state();
        static void run();
        static void stop();
};

