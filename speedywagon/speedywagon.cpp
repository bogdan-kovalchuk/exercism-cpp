#include "speedywagon.h"

#include <algorithm>
#include <numeric>

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

    bool alarm_control(pillar_men_sensor *sensor)
    {
        return sensor != nullptr && sensor->activity > 0;
    }

    bool uv_alarm(pillar_men_sensor *sensor)
    {
        return sensor != nullptr && uv_light_heuristic(&sensor->data) > sensor->activity;
    }

    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int> *readings)
    {
        const auto sum = std::accumulate(readings->begin(), readings->end(), 0);
        const auto average = static_cast<double>(sum) / readings->size();

        return static_cast<int>(std::count_if(readings->begin(), readings->end(), [average](int reading)
                                              { return reading > average; }));
    }

} // namespace speedywagon
