#include "power_of_troy.h"

namespace troy
{

    void give_new_artifact(human &person, std::string artifact_name)
    {
        person.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(
        std::unique_ptr<artifact> &first_possession,
        std::unique_ptr<artifact> &second_possession)
    {
        std::swap(first_possession, second_possession);
    }

} // namespace troy
