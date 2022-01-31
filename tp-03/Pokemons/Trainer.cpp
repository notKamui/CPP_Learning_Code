#include "Trainer.h"
#include "PC.h"

void Trainer::capture(std::unique_ptr<Pokemon> pokemon)
{
    pokemon->set_trainer(this);
    for (auto& pokeball : _pokeballs)
    {
        if (pokeball.empty())
        {
            pokeball.store(std::move(pokemon));
            return;
        }
    }
    _pc.receive(std::move(pokemon));
}

Trainer::Trainer(const std::string &name, PC &pc)
        : _name { name }
        , _pc { pc }
{}

const std::string &Trainer::name() const { return _name; }

const std::array<Pokeball, 6> &Trainer::pokeballs() const  { return _pokeballs; }

void Trainer::store_in_pc(int pos)
{
    _pc.receive(std::make_unique<Pokemon>(_pokeballs.at(pos).pokemon()));
    _pokeballs.at(pos) = Pokeball();
}