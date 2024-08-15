#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

class FuncContainer
{
    std::vector< std::function<void(void)> > funcs;

    public:
        FuncContainer();
        FuncContainer(void(*func)(void));

        int size();

        void run(int index);
        void runAll();

        void add(void(*func)(void));
        void remove(void(*func)(void));
        void remove(int index);
        void clear();
};

