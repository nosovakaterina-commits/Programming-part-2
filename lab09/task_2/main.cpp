#include "CollegeAthlete.h"
#include <iostream>

int main() {
    // Передаємо параметри
    CollegeAthlete studentAthlete("Kate Nosova", "Computer Science", 4.9, "Volleyball", 14, "NTU KhPI");

    // Виводимо об'єднаний профіль студента-спортсмена
    studentAthlete.showFullProfile();

    return 0;
}