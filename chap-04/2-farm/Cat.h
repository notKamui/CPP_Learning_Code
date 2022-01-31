#pragma once

#include "Animal.h"

#include <iostream>

class Cat : public Animal
{
public:
    void sing(char end) const override { std::cout << "Meow" << end; }
};
