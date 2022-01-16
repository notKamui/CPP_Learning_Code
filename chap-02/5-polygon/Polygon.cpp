#include "Polygon.h"

void Polygon::add_vertex(int x, int y)
{
    _vertices.emplace_back(x, y);
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (const auto& vertex : polygon._vertices)
    {
        stream << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    return stream;
}
const Vertex& Polygon::get_vertex(size_t index) const
{
    return _vertices[index];
}
