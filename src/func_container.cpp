#include "func_container.hpp"

FuncContainer::FuncContainer()
{

}

FuncContainer::FuncContainer(void(*func)(void))
{
    add(func);
}

int FuncContainer::size()
{
    return funcs.size();
}

void FuncContainer::run(int index)
{
    funcs.at(index)();
}

void FuncContainer::runAll()
{
    for (int i = 0; i < funcs.size(); i++)
    {
        run(i);
    }
    
}

void FuncContainer::add(void(*func)(void))
{
    std::function<void(void)> stdFunc = func;
    funcs.push_back(stdFunc);
}

void FuncContainer::remove(int index)
{
    funcs.erase(funcs.begin()+index);
}

void FuncContainer::remove(void(*func)(void))
{
    std::function<void(void)> stdFunc = func;

    for(int i = 0; i < funcs.size(); i++)
    {
        if(stdFunc.target<void(*)()>() == funcs[i].target<void(*)()>())
        {
            funcs.erase(funcs.begin()+i);
            break;
        }
    }
}

void FuncContainer::clear()
{
    funcs.clear();
}