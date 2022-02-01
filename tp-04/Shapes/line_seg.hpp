#pragma once

#include "line.hpp"

class LineSegment : public Line
{
public:
    using Line::Line;

    ~LineSegment() override = default;

    std::ostream& print(std::ostream& os) const override
    {
        return os << "segment from " << first << " to " << last;
    }
};
