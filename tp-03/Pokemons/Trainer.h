#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <memory>
#include <string>
#include <vector>

// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
        : _name { name }
        , _pc { pc }
    {}

    [[nodiscard]] const std::string& name() const { return _name; }

    [[nodiscard]] const std::vector<Pokeball>& pokeballs() const { return _pokeballs; }

    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        for (auto& pokeball : _pokeballs)
        {
            if (!pokeball.empty())
            {
                pokeball.store(std::move(pokemon));
                return;
            }
        }
        _pc.receive(std::move(pokemon));
    }

private:
    const std::string&    _name;
    PC&                   _pc;
    std::vector<Pokeball> _pokeballs = std::vector<Pokeball>(6);
};
