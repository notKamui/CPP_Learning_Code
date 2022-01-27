#pragma once

#include "Pokemon.h"

#include <memory>
#include <iostream>

// A ball where Pokemon sleep.
class Pokeball
{
public:
    [[nodiscard]] bool empty() const { return !_pokemon; }

    void store(std::unique_ptr<Pokemon> pokemon) { _pokemon = std::move(pokemon); }

    [[nodiscard]] Pokemon& pokemon() const { return *_pokemon; }

private:
    std::unique_ptr<Pokemon> _pokemon;
};