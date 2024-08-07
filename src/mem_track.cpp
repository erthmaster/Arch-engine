#ifdef MEM_TRACK

#include <iostream>
#include <cstdlib>
#include <new>

#include "mem_track.hpp"
#include "logging.hpp"

void* operator new(std::size_t size) 
{
    Log::info("MEM", "Malloc: " + std::to_string(size));
    
    void* ptr = malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void operator delete(void* ptr, std::size_t size) 
{
    Log::info("MEM", "Free: " + std::to_string(size));
    free(ptr);
}

#endif