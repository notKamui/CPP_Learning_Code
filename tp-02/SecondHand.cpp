#include "SecondHand.h"

void SecondHand::advance()
{
    _seconds++;
    if (_seconds == 60) {
        _seconds = 0;
        _min_hand.advance();
    }
}
