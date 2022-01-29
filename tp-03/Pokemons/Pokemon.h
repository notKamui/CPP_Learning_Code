#pragma once

#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    explicit Pokemon(const std::string& name)
        : _name(name)
    {}

    [[nodiscard]] const std::string& name() const { return _name; }

    void set_trainer(Trainer* trainer) { _trainer = trainer;}
    [[nodiscard]] Trainer* trainer() const { return _trainer; }

private:
    const std::string _name;
    Trainer*           _trainer {};
};
