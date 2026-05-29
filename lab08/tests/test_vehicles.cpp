#include <gtest/gtest.h>
#include <stdexcept>
#include <type_traits>
#include "Vehicle.h"
#include "Truck.h"
#include "RefrigeratedTruck.h"
#include "PassengerCar.h"

TEST(AbstractVehicleHierarchyTest, CannotInstantiateVehicleDirectly) {
    EXPECT_TRUE(std::is_abstract<Vehicle>::value);
}

TEST(AbstractVehicleHierarchyTest, PolymorphicCallsCorrectlyExecute) {
    Vehicle* item = new RefrigeratedTruck("Scania", 500, 9.0, 25.0, 3, -20.0, true);
    
    EXPECT_EQ(item->category(), "RefrigeratedTruck");
    EXPECT_NE(item->statusLine().find("temp: -20 C"), std::string::npos);

    delete item;
}

TEST(TruckTest, TransportCargoUpdatesCounter) {
    Truck truck("MAN TGX", 440, 7.5, 15.0, 2);
    
    EXPECT_EQ(truck.totalCargoTransported(), 0);
    truck.transportCargo(10);
    EXPECT_EQ(truck.totalCargoTransported(), 10);
}

TEST(RefrigeratedTruckTest, StateTransitions) {
    RefrigeratedTruck truck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, false);

    EXPECT_THROW(truck.deliveryFrozenGoods(5), std::runtime_error);
    truck.setCooling(true);
    EXPECT_NO_THROW(truck.deliveryFrozenGoods(5));
}

TEST(PassengerCarTest, DriveTripsIncrementsCounter) {
    PassengerCar car("Toyota Camry", 180, 1.6, 5, "Sedan");

    EXPECT_EQ(car.totalTrips(), 0);
    car.driveTrip();
    EXPECT_EQ(car.totalTrips(), 1);
}
