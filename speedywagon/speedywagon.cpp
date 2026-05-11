#include "speedywagon.h"

namespace speedywagon
{

    bool connection_check(pillar_men_sensor *sensor)
    {
        if (!sensor)
            return true;
            
        return false;
    }

    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int> *data_array)
    {
        double avg{};
        for (auto element : *data_array)
        {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array)
        {
            if (element > avg)
                ++uv_index;
        }
        return uv_index;
    }

} // namespace speedywagon
