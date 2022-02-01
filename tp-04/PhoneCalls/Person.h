#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Person
{
public:
    Person(std::string_view name, int position)
        : _name { name }
        , _position { position }
    {}

    void answer_phone() const { std::cout << "Hi! " << _name << " on the phone!" << std::endl; }

    [[nodiscard]] const std::string& name() const { return _name; }

    [[nodiscard]] int get_position() const { return _position; }

    void set_position(int position) { _position = position; }

private:
    const std::string _name;
    int               _position = 0;
};
