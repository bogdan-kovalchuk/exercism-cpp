#include "power_of_troy.h"

namespace troy
{

    void give_new_artifact(human &person, std::string artifact_name)
    {
        person.possession = std::make_unique<artifact>(artifact_name);
    }

} // namespace troy
