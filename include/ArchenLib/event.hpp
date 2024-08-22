#pragma once
#include <memory>

class Event
{
    class Impl;
    std::unique_ptr<Impl> impl_;

    public:
        Event();        
        ~Event();

        bool poll();        
        int type() const;
};