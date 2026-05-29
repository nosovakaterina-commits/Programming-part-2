#include <iostream>
#include "Vehicle.h"
#include "Truck.h"
#include "RefrigeratedTruck.h"
#include "PassengerCar.h"

int main() {
    const int FLEET_SIZE = 3;
    Vehicle* fleet[FLEET_SIZE];

    fleet[0] = new Truck("MAN TGX", 440, 7.5, 15.0, 2);
    fleet[1] = new RefrigeratedTruck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, true);
    fleet[2] = new PassengerCar("Toyota Camry", 180, 1.6, 5, "Sedan");

    static_cast<Truck*>(fleet[0])->transportCargo(10);
    static_cast<RefrigeratedTruck*>(fleet[1])->deliveryFrozenGoods(15);
    static_cast<PassengerCar*>(fleet[2])->driveTrip();

    std::cout << "=== Runtime Polymorphism Demonstration ===\n\n";
    for (int i = 0; i < FLEET_SIZE; ++i) {
        std::cout << fleet[i]->statusLine() << "\n";
    }

    std::cout << "\n=== Memory Analysis (sizeof) ===\n\n";
    std::cout << "sizeof(void*)              = " << sizeof(void*) << "\n";
    std::cout << "sizeof(Vehicle)            = " << sizeof(Vehicle) << "\n";
    std::cout << "sizeof(Truck)              = " << sizeof(Truck) << "\n";
    std::cout << "sizeof(RefrigeratedTruck)  = " << sizeof(RefrigeratedTruck) << "\n";
    std::cout << "sizeof(PassengerCar)       = " << sizeof(PassengerCar) << "\n";

    for (int i = 0; i < FLEET_SIZE; ++i) {
        delete fleet[i];
    }

    return 0;
}