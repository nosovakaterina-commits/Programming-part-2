#include <gtest/gtest.h>
#include <stdexcept>

#include "Car.hpp"

TEST(CarTest, StartsWorkingAfterEngineOn) {
    Car car(2000, 4);
    car.startEngine();

    EXPECT_TRUE(car.isEngineRunning());
    EXPECT_EQ(car.getStatusMessage(), "Engine started.");
}

TEST(CarTest, AccelerationIncreasesSpeed) {
    Car car(2000, 4);
    car.startEngine();

    car.accelerate();

    EXPECT_EQ(car.getSpeed(), 10);
    EXPECT_LT(car.getRemainingFuel(), 60);
}

TEST(CarTest, AccelerationConsumesMoreFuelThanBraking) {
    Car car(2000, 4);
    car.startEngine();

    car.accelerate();
    int fuelAfterAccelerate = car.getRemainingFuel();

    car.brake();
    int fuelAfterBrake = car.getRemainingFuel();

    EXPECT_EQ(fuelAfterAccelerate, fuelAfterBrake);
}

TEST(CarTest, BrakingDecreasesSpeed) {
    Car car(2000, 4);
    car.startEngine();

    for (int i = 0; i < 60; ++i) {
        car.accelerate();
    }

    EXPECT_EQ(car.getRemainingFuel(), 0);
    EXPECT_THROW(car.accelerate(), std::runtime_error);
}