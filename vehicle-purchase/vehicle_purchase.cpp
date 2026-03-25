#include "vehicle_purchase.h"

namespace vehicle_purchase
{

    // needs_license determines whether a license is needed to drive a type of
    // vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind)
    {
        if (kind == "car" || kind == "truck")
        {
            return true;
        }

        return false;
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends the
    // vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2)
    {
        std::string option = option1;
        if (option1 > option2)
        {
            option = option2;
        }

        return option + " is clearly the better choice.";
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a~
    // certain age.
    double calculate_resell_price(double original_price, double age)
    {
        double age_coefficient = 0.5;
        if (age < 3.0)
        {
            age_coefficient = 0.8;
        }
        else if (age >= 3.0 && age < 10)
        {
            age_coefficient = 0.7;
        }

        return age_coefficient * original_price;
    }

} // namespace vehicle_purchase
