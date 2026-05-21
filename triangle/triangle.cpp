#include "triangle.h"

namespace triangle
{
    flavor kind(double x, double y, double z)
    {
        if (x <= 0 || y <= 0 || z <= 0)
            throw std::domain_error("invalid triangle");

        if (x + y <= z || x + z <= y || y + z <= x)
            throw std::domain_error("invalid triangle");

        if (x == y && y == z)
            return flavor::equilateral;

        if (x == y || x == z || y == z)
            return flavor::isosceles;

        return flavor::scalene;
    }

} // namespace triangle
