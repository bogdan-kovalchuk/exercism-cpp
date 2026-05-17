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

} // namespace troy
