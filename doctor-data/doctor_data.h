#pragma once

#include <string>

namespace star_map
{
    enum class System
    {
        Sol,
        BetaHydri,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };

}

namespace heaven
{
    class Vessel
    {
    public:
        Vessel(std::string name, int generation, star_map::System current_system = star_map::System::Sol);

        std::string name;
        int generation = 0;
        star_map::System current_system = star_map::System::Sol;
        int busters = 0;

        Vessel replicate(std::string new_name) const;
        void make_buster();
        bool shoot_buster();
    };

    std::string get_older_bob(const Vessel& first, const Vessel& second);
    bool in_the_same_system(const Vessel& first, const Vessel& second);

}
