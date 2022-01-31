#include "Car.h"
#include "Scooter.h"
#include "Vehicle.h"

#include <iostream>

// int main()
//{
//     Driver     car_driver;
//     Car        car { car_driver, 60u };
//     const auto distance_in_car = car.drive();
//     std::cout << distance_in_car << " km in a car." << std::endl;
//
//     Driver     mini_gangster;
//     Scooter    scooter { mini_gangster, 180u };
//     const auto distance_in_scooter = scooter.drive();
//     std::cout << distance_in_scooter << " km with a scooter." << std::endl;
//
//     return 0;
// }

class Food
{
public:
    virtual ~Food() {};
    virtual void miam_miam() const = 0;

protected:
    Food() {};
};

class Nutella : public Food
{
public:
    void miam_miam() const override { std::cout << "Nutella" << std::endl; }
};

int main()
{
    // The following shouldn't compile :
    // Food food;

    Nutella nutella;
    nutella.miam_miam(); // -> "Nutella"

    Food& nutella_as_food = nutella;
    nutella_as_food.miam_miam(); // -> "Nutella"

    const Food& nutella_as_cfood = nutella;
    nutella_as_cfood.miam_miam(); // -> "Nutella"

    std::cout << "fin" << std::endl;

    return 0;
}