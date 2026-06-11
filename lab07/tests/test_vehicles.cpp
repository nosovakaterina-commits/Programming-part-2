#include <gtest/gtest.h>
#include <stdexcept>

#include "Truck.h"
#include "RefrigeratedTruck.h"
#include "PassengerCar.h"

TEST(VehicleHierarchyTest, RefrigeratedTruckKeepsInheritedAndOwnState) {
    RefrigeratedTruck truck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, true);

    EXPECT_EQ(truck.brand(), "Volvo FH");
    EXPECT_EQ(truck.powerHp(), 540);
    EXPECT_DOUBLE_EQ(truck.maxLoadCapacity(), 20.0);
    EXPECT_EQ(truck.axleCount(), 3);
    EXPECT_DOUBLE_EQ(truck.minTemperature(), -18.5);
    EXPECT_TRUE(truck.isCoolingActive());
    EXPECT_EQ(truck.totalCargoTransported(), 0);
}

TEST(VehicleHierarchyTest, DeliveryFrozenGoodsConsumesCargoAndUpdatesCounters) {
    RefrigeratedTruck truck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, true);

    truck.deliveryFrozenGoods(12);

    EXPECT_EQ(truck.totalCargoTransported(), 12);
}

TEST(VehicleHierarchyTest, RefrigeratedTruckRejectsDeliveryWhenCoolingOff) {
    RefrigeratedTruck truck("Volvo FH", 540, 8.5, 20.0, 3, -18.5, false);

    EXPECT_THROW(truck.deliveryFrozenGoods(5), std::runtime_error);
}

TEST(VehicleHierarchyTest, PassengerCarOverridesStatusAndIncrementsTrips) {
    PassengerCar car("Toyota Camry", 180, 1.6, 5, "Sedan");

    EXPECT_EQ(car.category(), "PassengerCar");
    EXPECT_NE(car.statusLine().find("trips: 0"), std::string::npos);

    car.driveTrip();

    EXPECT_EQ(car.totalTrips(), 1);
}

TEST(VehicleHierarchyTest, BaseTruckRejectsInvalidCargoWeight) {
    Truck truck("MAN", 400, 7.0, 15.0, 2);

    EXPECT_THROW(truck.transportCargo(0), std::invalid_argument);
}