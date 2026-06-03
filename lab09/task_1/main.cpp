#include "TouchDisplay.h"
#include <iostream>

int main() {
    // Створюємо об'єкт TouchDisplay 
    TouchDisplay* myDisplay = new TouchDisplay("ASUS ProArt Screen", 144, "3840x2160");

    // Перевіряємо роботу функції togglePower(). 
    myDisplay->describe();

    std::cout << "\n";

    // Перевіряємо роботу поліморфізму через вказівник на базовий корінь Device
    Device* polyDevice = myDisplay;
    polyDevice->togglePower(); // Вимикаємо пристрій через загальний інтерфейс бази

    // Очищаємо пам'ять (викликаються деструктори у правильному порядку)
    delete myDisplay; 

    return 0;
}