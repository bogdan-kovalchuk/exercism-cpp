#include "grade_school.h"

#include <algorithm>
#include <utility>

namespace grade_school
{

    void school::add(std::string name, int grade)
    {
        auto &students = students_[grade];
        const auto insert_at = std::lower_bound(students.begin(), students.end(), name);
        students.insert(insert_at, std::move(name));
    }

    school::roster_type school::roster() const
    {
        return students_;
    }

    school::students_type school::grade(int grade_number) const
    {
        if (const auto it = students_.find(grade_number); it != students_.end())
        {
            return it->second;
        }

        return {};
    }

} // namespace grade_school
