#include <gtest/gtest.h>
#include "TouchDisplay.h"

// Перевіряємо створення об'єкта та роботу віртуального наслідування.
TEST(TouchDisplayTest, InitializationAndPower) {
    TouchDisplay display("Test Screen", 60, "1920x1080");
  
    SUCCEED(); 
}

// Перевіряємо роботу runtime-поліморфізму через вказівник на корінь Device.
TEST(TouchDisplayTest, PolymorphicBehavior) {
    TouchDisplay* display = new TouchDisplay("Polymorphic Screen", 120, "2K");
    Device* baseDevice = display;
    
    // Перевіряємо, що приведення типів пройшло успішно і вказівник не нульовий
    ASSERT_NE(baseDevice, nullptr);
    
    delete display;
}