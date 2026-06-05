#include "nucleotide_count.h"

namespace nucleotide_count
{

    // TODO: add your solution here
    std::map<char, int> count(const std::string &strand)
    {
        std::map<char, int> result{
            {'A', 0},
            {'C', 0},
            {'G', 0},
            {'T', 0}};

        for (char c : strand)
        {
            switch (c)
            {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                result[c]++;
                break;

            default:
                throw std::invalid_argument("Invalid nucleotide");
            }
        }

        return result;
    }

} // namespace nucleotide_count
