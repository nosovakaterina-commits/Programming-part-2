#include <gtest/gtest.h>
#include "CollegeAthlete.h"

TEST(CollegeAthleteTest, CheckStudentData) {
    CollegeAthlete athlete("Kate Nosova", "Computer Science", 4.9, "Volleyball", 14, "NTU KhPI");
    
    // Перевіряємо, чи правильно зберігся і повертається середній бал
    EXPECT_DOUBLE_EQ(athlete.getGpa(), 4.9);
}

TEST(CollegeAthleteTest, CheckAthleteData) {
    CollegeAthlete athlete("Kate Nosova", "Computer Science", 4.9, "Volleyball", 14, "NTU KhPI");
    
    // Перевіряємо, чи правильно зберігся і повертається вид спорту
    EXPECT_EQ(athlete.getSportType(), "Volleyball");
}