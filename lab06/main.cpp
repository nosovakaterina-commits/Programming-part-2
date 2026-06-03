#include <iostream>

#include "Car.hpp"

int main() {
    Car car(2000, 4);

    car.startEngine();
    std::cout << car.getStatusMessage() << '\n';

    car.accelerate();
    std::cout << car.getStatusMessage() << '\n';

    car.accelerate();
    std::cout << car.getStatusMessage() << '\n';

    std::cout << "Current speed: " << car.getSpeed() << " km/h\n";
    std::cout << "Engine RPM: " << car.getEngineRPM() << " rpm\n";
    std::cout << "Remaining fuel: " << car.getRemainingFuel() << " L\n";

    car.brake();
    std::cout << car.getStatusMessage() << '\n';

    car.refuel(20);
    std::cout << car.getStatusMessage() << '\n';

    car.stopEngine();
    std::cout << car.getStatusMessage() << '\n';

    return 0;
}