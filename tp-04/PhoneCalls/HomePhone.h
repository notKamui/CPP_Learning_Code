#pragma once

#include "Person.h"
#include "Phone.h"

class HomePhone : public Phone
{
public:
    HomePhone(const Person& owner, int position)
        : Phone { owner }
        , _position { position }
    {}

    void ring() const override
    {
        if (_owner.get_position() != _position)
        {
            std::cout << "This is the voicemail of " << _owner.name() << ". Please leave a message."
                      << std::endl;
        }
        else
        {
            Phone::ring();
        }
    }

private:
    int _position;
};