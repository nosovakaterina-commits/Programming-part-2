#include "TouchDisplay.h"
#include <iostream>


TouchDisplay::TouchDisplay(std::string name, int rate, std::string res)
    : Device(name),               // Корінь ієрархії.
      InputDevice(name, rate),     // Проміжний клас введення.
      OutputDevice(name, res)      // Проміжний клас виведення.
{}

void TouchDisplay::describe() const {
    // Завдяки віртуальному наслідуванню ми маємо прямий та однозначний доступ до властивостей спільного базового класу Device!
    std::cout << "Device Name: " << deviceName << " | Current Power: " 
              << (isOn ? "ON" : "OFF") << "\n";
              
    // Викликаємо унікальну поведінку батьківських гілок
    InputDevice::describe();
    OutputDevice::describe();
    
}