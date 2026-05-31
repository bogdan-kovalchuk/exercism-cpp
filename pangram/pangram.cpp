#include "pangram.h"

#include <cctype>

namespace pangram
{
    bool is_pangram(const std::string &s)
    {
        bool letters[26] = {};

        for (unsigned char ch : s)
        {
            ch = std::tolower(ch);

            if (ch >= 'a' && ch <= 'z')
            {
                letters[ch - 'a'] = true;
            }
        }

        for (bool exists : letters)
        {
            if (!exists)
            {
                return false;
            }
        }

        return true;
    }

} // namespace pangram