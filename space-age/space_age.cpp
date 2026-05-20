#include "space_age.h"

namespace space_age
{
    // TODO: add your solution here
    space_age::space_age(int64_t age) : age(age) {}

    int64_t space_age::seconds() const
    {
        return age;
    }
    double space_age::on_mercury() const
    {
        return age / 31557600.0 / 0.2408467;
    }

    double space_age::on_venus() const
    {
        return age / 31557600.0 / 0.61519726;
    }

    double space_age::on_earth() const
    {
        return age / 31557600.0;
    }

    double space_age::on_mars() const
    {
        return age / 31557600.0 / 1.8808158;
    }

    double space_age::on_jupiter() const
    {
        return age / 31557600.0 / 11.862615;
    }

    double space_age::on_saturn() const
    {
        return age / 31557600.0 / 29.447498;
    }

    double space_age::on_uranus() const
    {
        return age / 31557600.0 / 84.016846;
    }

    double space_age::on_neptune() const
    {
        return age / 31557600.0 / 164.79132;
    }

} // namespace space_age
