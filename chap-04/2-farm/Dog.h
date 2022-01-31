#pragma once

#include "Animal.h"

#include <iostream>

class Dog : public Animal
{
public:
    void sing(char end) const override { std::cout << "Waf" << end; }
};
