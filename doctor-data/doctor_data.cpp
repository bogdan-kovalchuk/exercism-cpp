#include "doctor_data.h"

#include <utility>

namespace heaven
{

Vessel::Vessel(std::string name, int generation, star_map::System current_system)
    : name{std::move(name)}, generation{generation}, current_system{current_system}
{
}

Vessel Vessel::replicate(std::string new_name) const
{
    return Vessel{std::move(new_name), generation + 1};
}

void Vessel::make_buster()
{
    ++busters;
}

bool Vessel::shoot_buster()
{
    if (busters == 0)
    {
        return false;
    }

    --busters;
    return true;
}

std::string get_older_bob(const Vessel& first, const Vessel& second)
{
    if (first.generation < second.generation)
    {
        return first.name;
    }

    return second.name;
}

bool in_the_same_system(const Vessel& first, const Vessel& second)
{
    return first.current_system == second.current_system;
}

} // namespace heaven
