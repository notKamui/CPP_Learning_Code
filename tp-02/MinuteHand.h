#pragma once

class MinuteHand
{
public:
    [[nodiscard]] int get_minutes() const { return _minutes; };

    void advance();

private:
    int _minutes = 0;
};

