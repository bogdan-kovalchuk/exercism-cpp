#pragma once
#include <stdint.h>

namespace space_age
{
    // TODO: add your solution here
    class space_age
    {
    private:
        int64_t age;

    public:
        space_age(int64_t age);
        int64_t seconds() const;
        double on_mercury() const;
        double on_venus() const;
        double on_earth() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;
    };

} // namespace space_age
