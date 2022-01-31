#pragma once

#include "Pokeball.h"
#include "Pokemon.h"
#include "PC.h"

#include <array>
#include <memory>
#include <string>

// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc);

    [[nodiscard]] const std::string& name() const;

    [[nodiscard]] const std::array<Pokeball, 6>& pokeballs() const;

    void capture(std::unique_ptr<Pokemon> pokemon);

    void store_in_pc(int pos);

private:
    const std::string       _name;
    PC&                     _pc;
    std::array<Pokeball, 6> _pokeballs;
};
