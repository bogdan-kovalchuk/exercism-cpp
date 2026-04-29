#include <algorithm>
#include <string>
#include <vector>

namespace election
{

    struct ElectionResult
    {
        std::string name{};
        int votes{};
    };

    int vote_count(const ElectionResult &result)
    {
        return result.votes;
    }

    void increment_vote_count(ElectionResult &result, int number_of_votes)
    {
        result.votes += number_of_votes;
    }

    ElectionResult &determine_result(std::vector<ElectionResult> &candidates)
    {
        auto winner = std::max_element(
            candidates.begin(),
            candidates.end(),
            [](const ElectionResult &lhs, const ElectionResult &rhs)
            {
                return lhs.votes < rhs.votes;
            });

        winner->name = "President " + winner->name;
        return *winner;
    }

} // namespace election
