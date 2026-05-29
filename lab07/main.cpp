#include <iostream>

#include "Vehicle.h"
#include "Truck.h"
#include "RefrigeratedTruck.h"
#include "PassengerCar.h"

int main() {
    RefrigeratedTruck refTruck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, true);
    PassengerCar cityCar("Toyota Camry", 180, 1.6, 5, "Sedan");

    refTruck.deliveryFrozenGoods(15);
    cityCar.driveTrip();

    std::cout << refTruck.statusLine() << "\n";
    std::cout << cityCar.statusLine() << "\n\n";

    std::cout << "sizeof(Vehicle) = " << sizeof(Vehicle) << "\n";
    std::cout << "sizeof(Truck) = " << sizeof(Truck) << "\n";
    std::cout << "sizeof(RefrigeratedTruck) = " << sizeof(RefrigeratedTruck) << "\n";
    std::cout << "sizeof(PassengerCar) = " << sizeof(PassengerCar) << "\n";

    return 0;
}