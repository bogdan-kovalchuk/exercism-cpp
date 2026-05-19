#include "reverse_string.h"

namespace reverse_string
{
    std::string reverse_string(const std::string &s)
    {
        std::string reversed(s.length(), ' ');

        for (size_t i = 0; i < s.length(); ++i)
            reversed[i] = s[s.length() - 1 - i];

        return reversed;
    }
}
