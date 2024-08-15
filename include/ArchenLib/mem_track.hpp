#pragma once
#include <iostream>

void* operator new(std::size_t size);
void operator delete(void* ptr);