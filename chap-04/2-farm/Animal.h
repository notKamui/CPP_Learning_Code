#pragma once

#include <iostream>

class Animal
{
public:
    virtual void sing(char end) const { std::cout << "..." << end; }

    virtual ~Animal() = default;
};
