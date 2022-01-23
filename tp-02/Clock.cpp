#include "Clock.h"

std::ostream& operator<<(std::ostream& os, const Clock& clock)
{
    os << clock._min_hand.get_minutes() << " min " << clock._sec_hand.get_seconds() << " sec";
    return os;
}
void Clock::tick()
{
    _sec_hand.advance();

    auto curr_event = std::begin(_events);
    while (curr_event != std::end(_events))
    {
        if (curr_event->notify_time(_min_hand.get_minutes(), _sec_hand.get_seconds()))
            curr_event = _events.erase(curr_event);
        else
            ++curr_event;
    }
}
