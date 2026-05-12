#include "speedywagon.h"

namespace speedywagon
{

    bool connection_check(pillar_men_sensor *sensor)
    {
        return sensor != nullptr;
    }

    int activity_counter(pillar_men_sensor *sensors, int sensor_count)
    {
        int total_activity{};

        for (int index{}; index < sensor_count; ++index)
        {
            total_activity += sensors[index].activity;
        }

        return total_activity;
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
