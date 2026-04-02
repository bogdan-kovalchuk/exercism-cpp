#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores)
{
    // TODO: Implement round_down_scores
    std::vector<int> rounded;
    for (auto score : student_scores)
    {
        rounded.push_back(static_cast<int>(score));
    }
    return rounded;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores)
{
    // TODO: Implement count_failed_students
    int count = 0;
    for (auto score : student_scores)
    {
        if (score <= 40)
            count++;
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score)
{
    const int FAIL_THRESHOLD = 40;
    const int FIRST_PASS_SCORE = FAIL_THRESHOLD + 1;

    int interval_size = (highest_score - FAIL_THRESHOLD) / 4;

    std::array<int, 4> thresholds{};

    for (int i = 0; i < 4; ++i)
    {
        thresholds[i] = FIRST_PASS_SCORE + i * interval_size;
    }

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names)
{
    // TODO: Implement student_ranking
    std::vector<std::string> ranking;
    ranking.reserve(student_scores.size());

    for (size_t i = 0; i < student_scores.size(); ++i)
    {
        ranking.push_back(
            std::to_string(i + 1) + ". " +
            student_names[i] + ": " +
            std::to_string(student_scores[i]));
    }

    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names)
{
    // TODO: Implement perfect_score
    for (size_t i = 0; i < student_scores.size(); ++i)
    {
        const int MAX_SCORE = 100;

        if (student_scores[i] == MAX_SCORE)
            return student_names[i];
    }
    return "";
}
