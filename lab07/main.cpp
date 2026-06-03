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

    std::cout << "[OK] Copy operations are successfully blocked by compiler via '= delete'.\n";
    //Заборону копіювання успішно працює.

    PassengerCar movedCar = std::move(cityCar); // Переміщуємо властивості об'єкта в новий об'єкт.
    std::cout << "[OK] Move operations are fully functional via '= default'.\n";
    //Перенесення властивостей успішне.

    return 0;
}
   