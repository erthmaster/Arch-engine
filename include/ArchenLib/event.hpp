#pragma once
#include <memory>

class Event
{
    class Impl;
    std::unique_ptr<Impl> pImpl;

    public:
        Event();        
        ~Event();

        bool poll();        
        int type() const;
};