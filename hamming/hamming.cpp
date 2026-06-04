#include "hamming.h"

#include <stdexcept>

namespace hamming
{

    int compute(const std::string &first, const std::string &second)
    {
        if (first.length() != second.length())
        {
            throw std::domain_error("DNA strands must be of equal length");
        }

        int distance = 0;

        for (std::size_t i = 0; i < first.length(); ++i)
        {
            if (first[i] != second[i])
            {
                ++distance;
            }
        }

        return distance;
    }

}