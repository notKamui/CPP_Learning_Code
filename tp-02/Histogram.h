#pragma once

#include <string>
#include <vector>
#include <iostream>

class Histogram
{
public:
    Histogram()
    = default;

    Histogram(const Histogram& other)
        : _count(other._count)
    {
        std::cout << "Copy constructor called" << std::endl;
    }

    void analyze(const std::string&);
    void print() const;

private:
    std::vector<unsigned int> _count = std::vector<unsigned int>(26, 0);
};