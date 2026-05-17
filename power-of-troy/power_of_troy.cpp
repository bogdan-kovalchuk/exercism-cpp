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

    void manifest_power(human &person, std::string power_effect)
    {
        person.own_power = std::make_shared<power>(power_effect);
    }

    void use_power(human &caster, human &target)
    {
        target.influenced_by = caster.own_power;
    }

} // namespace troy
