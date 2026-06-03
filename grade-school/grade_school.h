#pragma once

#include <map>
#include <string>
#include <vector>

namespace grade_school
{
    class school
    {
    public:
        using students_type = std::vector<std::string>;
        using roster_type = std::map<int, students_type>;

        void add(std::string name, int grade);
        roster_type roster() const;
        students_type grade(int grade_number) const;

    private:
        roster_type students_;
    };

} // namespace grade_school
