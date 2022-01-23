#pragma once

#include <ostream>
#include <vector>
#include "MinuteHand.h"
#include "SecondHand.h"
#include "Event.h"

class Clock
{
public:
    Clock(MinuteHand& min_hand, SecondHand& sec_hand)
        : _min_hand(min_hand)
        , _sec_hand(sec_hand)
    {}

    void tick();
    void add_event(const Event& event) { _events.emplace_back(event); }

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock);

private:
    MinuteHand& _min_hand;
    SecondHand& _sec_hand;
    std::vector<Event> _events;
};

std::ostream& operator<<(std::ostream& os, const Clock& clock);
