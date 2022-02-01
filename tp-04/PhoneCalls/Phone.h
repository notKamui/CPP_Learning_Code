#pragma once

#include "Person.h"

class Phone
{
public:
    virtual ~Phone() = default;

    virtual void ring() const { _owner.answer_phone(); }

protected:
    Phone(const Person& owner)
        : _owner { owner }
    {}

    const Person& _owner;

private:
    Phone(const Phone&) = default;
};
