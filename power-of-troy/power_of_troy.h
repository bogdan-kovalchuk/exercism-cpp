#pragma once

#include <string>
#include <memory>

namespace troy
{

    struct artifact
    {
        artifact(std::string name) : name(name) {}
        std::string name;
    };

    struct power
    {
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };

    struct human
    {
        std::unique_ptr<artifact> possession = nullptr;
        std::shared_ptr<power> own_power = nullptr;
        std::shared_ptr<power> influenced_by = nullptr;
    };

    void give_new_artifact(human &person, std::string artifact_name);

    void exchange_artifacts(
        std::unique_ptr<artifact> &first_possession,
        std::unique_ptr<artifact> &second_possession);

    void manifest_power(human &person, std::string power_effect);

    void use_power(human &caster, human &target);

    int power_intensity(human &person);

} // namespace troy
