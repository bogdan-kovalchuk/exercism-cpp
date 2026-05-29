#include "grains.h"
#include <stdexcept>
#include <cmath>

namespace grains
{

    long long square(int n)
    {
        if (n < 1 || n > 64)
        {
            throw std::domain_error("square must be between 1 and 64");
        }

        return static_cast<long long>(std::pow(2, n - 1));
    }

    long long total()
    {
        long long sum = 0;

        for (int i = 1; i <= 64; ++i)
        {
            sum += square(i);
        }

        return sum;
    }

} // namespace grains