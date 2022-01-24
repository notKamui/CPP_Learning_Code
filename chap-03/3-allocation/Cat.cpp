#include "Cat.h"

#include <iostream>
#include <memory>

int main()
{
    auto cat = std::make_unique<Cat>("Mr Meow");
    std::cout << *cat << std::endl;

    std::unique_ptr<Cat> cat2;
    if (cat2 == nullptr)
    {
        std::cout << "cat2 is nullptr" << std::endl;
    }
    cat2 = std::make_unique<Cat>("Nekosan");

    std::cout << "cat1 == cat2 ? " << (cat == cat2) << std::endl;
    std::cout << "*cat1 == *cat2 ? " << (*cat == *cat2) << std::endl;

    cat.reset();
    if (cat == nullptr)
    {
        std::cout << "cat is nullptr" << std::endl;
    }

    return 0;
}