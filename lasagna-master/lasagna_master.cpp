#include "lasagna_master.h"

namespace lasagna_master
{

    int preparationTime(const std::vector<std::string> &layers, int preparation_time)
    {
        return static_cast<int>(layers.size()) * preparation_time;
    }

    amount quantities(const std::vector<std::string> &layers)
    {
        amount totals{0, 0.0};

        for (const auto &layer : layers)
        {
            if (layer == "noodles")
            {
                totals.noodles += 50;
            }
            else if (layer == "sauce")
            {
                totals.sauce += 0.2;
            }
        }

        return totals;
    }

    void addSecretIngredient(std::vector<std::string> &my_list, const std::vector<std::string> &friends_list)
    {
        my_list.back() = friends_list.back();
    }

    std::vector<double> scaleRecipe(const std::vector<double> &quantities, int number_of_portions)
    {
        constexpr double base_portions{2.0};
        const double scale{number_of_portions / base_portions};

        std::vector<double> scaled_quantities;
        scaled_quantities.reserve(quantities.size());

        for (const auto &quantity : quantities)
        {
            scaled_quantities.push_back(quantity * scale);
        }

        return scaled_quantities;
    }

    void addSecretIngredient(std::vector<std::string> &my_list, const std::string &secret_ingredient)
    {
        my_list.back() = secret_ingredient;
    }

} // namespace lasagna_master
