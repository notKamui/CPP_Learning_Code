#include "Histogram.h"
#include <iostream>
#include <string>

void Histogram::analyze(const std::string& s)
{
    for (auto c : s)
        if (c >= 'a' && c <= 'z')
            _count[c - 'a'] += 1;

}

void Histogram::print() const
{
    for (auto c = 'a'; c <= 'z'; c++)
        std::cout << c << " : " << _count[c - 'a'] << std::endl;
}

int main() {
    Histogram h;
    h.print();
    h.analyze("Hello, world!");
    h.print();

    Histogram h1, h2;
    Histogram h3 { Histogram { h1 } };
    return 0;
}