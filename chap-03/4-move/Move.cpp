#include <iostream>
#include <memory>
#include <utility>

void display(const std::string& variable_name, const std::unique_ptr<int>& variable)
{
    if (variable)
    {
        std::cout << variable_name << " contains " << *variable << std::endl;
    }
    else
    {
        std::cout << variable_name << " is empty" << std::endl;
    }
}

std::unique_ptr<int> passthrough(std::unique_ptr<int> ptr)
{
    display("ptr", ptr);

    auto moved_ptr = std::move(ptr);
    display("moved_ptr", moved_ptr);
    display("ptr", ptr);

    return moved_ptr;
}

int main()
{
    auto i1 = std::make_unique<int>(3);
    auto i2 = std::make_unique<int>(8);

    std::cout << "Before passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    i2 = passthrough(std::move(i1));

    std::cout << "After passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    return 0;
}
