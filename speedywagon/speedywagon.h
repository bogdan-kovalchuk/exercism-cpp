#pragma once

#include <string>
#include <vector>

namespace speedywagon
{

    struct pillar_men_sensor
    {
        int activity{};
        std::string location{};
        std::vector<int> data{};
    };

    bool connection_check(pillar_men_sensor *sensor);
    int uv_light_heuristic(std::vector<int> *data_array);

} // namespace speedywagon
