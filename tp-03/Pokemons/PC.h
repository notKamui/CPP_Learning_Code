#pragma once

#include "Pokemon.h"
#include "Trainer.h"

#include <memory>
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    [[nodiscard]] const std::vector<std::unique_ptr<Pokemon>>& pokemons() const { return _pokemons; }

    void receive(std::unique_ptr<Pokemon> pokemon) { _pokemons.emplace_back(std::move(pokemon)); }

    void give_back(Trainer& trainer, const std::string& name)
    {
        for (int i = 0; i < (int)_pokemons.size(); ++i)
        {
            if (_pokemons[i]->name() == name && _pokemons[i]->trainer() == &trainer)
            {
                trainer.capture(std::move(_pokemons[i]));
                _pokemons.erase(_pokemons.begin() + i);
                return;
            }
        }
    }

private:
    std::vector<std::unique_ptr<Pokemon>> _pokemons;
};
