#pragma once
#include "color.hpp"
#include "node.hpp"
#include "renderer.hpp"
#include "window.hpp"
#include "event.hpp"

class App final
{
    public:
        App() = delete;

        static void init(
                            int = 800, 
                            int = 600,
                            const char* = "Archen game",
                            float = 60,
                            Color = LIGHT_GRAY,
                            Node* = nullptr
                        );

        static bool isRunning;
        static float maxFPS;

        static Event event;
        static Renderer* activeRender;
        static Window* window;
        static Node* coreNode;

        static int winWidth;
        static int winHeight;
        static char* winTitle;

        static Color bgColor;
};