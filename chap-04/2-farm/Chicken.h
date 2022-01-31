#pragma once

#include "Animal.h"

#include <iostream>

class Chicken : public Animal
{
public:
    void sing(char end) const override { std::cout << "Cotcotcotcodet" << end; }

    ~Chicken() override { std::cout << "CotCooooooooot!" << std::endl; }
};
