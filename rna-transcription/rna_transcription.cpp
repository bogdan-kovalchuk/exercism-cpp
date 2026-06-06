#include "rna_transcription.h"

namespace rna_transcription
{

    char to_rna(char nucleotide)
    {
        switch (nucleotide)
        {
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'A':
            return 'U';
        default:
            throw std::invalid_argument{"invalid nucleotide"};
        }
    }

    std::string to_rna(std::string dna)
    {
        std::transform(dna.begin(), dna.end(), dna.begin(),
                       [](char c)
                       { return to_rna(c); });
        return dna;
    }

} // namespace rna_transcription