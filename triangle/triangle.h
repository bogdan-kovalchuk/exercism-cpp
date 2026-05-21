#pragma once

#include <stdexcept>

namespace triangle
{
    // TODO: add your solution here
    enum flavor
    {
        equilateral,
        isosceles,
        scalene
    };

    flavor kind(double x, double y, double z);

} // namespace triangle
