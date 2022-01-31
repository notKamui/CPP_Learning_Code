#include "PC.h"
#include "Trainer.h"

const std::vector<std::unique_ptr<Pokemon>> &PC::pokemons() const { return _pokemons; }

void PC::receive(std::unique_ptr<Pokemon> pokemon) { _pokemons.emplace_back(std::move(pokemon)); }

void PC::give_back(Trainer &trainer, const std::string &name) {
    for (int i = 0; i < (int) _pokemons.size(); ++i) {
        if (_pokemons[i]->name() == name && _pokemons[i]->trainer() == &trainer) {
            trainer.capture(std::move(_pokemons[i]));
            _pokemons.erase(_pokemons.begin() + i);
            return;
        }
    }
}
