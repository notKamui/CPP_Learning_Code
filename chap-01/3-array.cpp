#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{

    if (argc <= 1)
    {
        std::cerr << "Missing argument" << std::endl;
        return -1;
    }

    int length = std::stoi(argv[1]);
    if (length < 0)
    {
        std::cerr << "Invalid argument, must be positive" << std::endl;
        return -1;
    }

    std::vector<int> array;

    array.reserve(length);
    for (int i = 0; i < length; i++)
    {
        array.emplace_back(i + 1);
    }

    for (int n : array)
    {
        std::cout << n << std::endl;
    }
    return 0;
}
