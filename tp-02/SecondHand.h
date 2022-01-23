#pragma once

#include "MinuteHand.h"

class SecondHand
{
public:
    SecondHand(MinuteHand& minute_hand)
        : _min_hand(minute_hand)
    {}

    [[nodiscard]] int get_seconds() const { return _seconds; }

    void advance();

private:
    int _seconds = 0;
    MinuteHand& _min_hand;
};
