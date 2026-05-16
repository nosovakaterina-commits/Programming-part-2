#include <gtest/gtest.h>
#include "Student.hpp"

TEST(StudentConstructorTest, StoresPositiveValues) {
    Student student(5, 1, 92.3, true, 15);

    EXPECT_EQ(student.getId(), 5);
    EXPECT_EQ(student.getCourse(), 1);
    EXPECT_DOUBLE_EQ(student.getAverageGrade(), 92.3);
    EXPECT_TRUE(student.getScholarship() );
    EXPECT_EQ(student.getAbsences(), 15);
}

TEST(StudentConstructorTest,  ReplacesInvalidValue) {
    Student student(-12, 5, 10.0, false, -64);

    EXPECT_EQ(student.getId(), 0);
    EXPECT_EQ(student.getAbsences(), 0);
}

TEST(StudentStateTest, PromoteToNextChangeState) {
    Student student(1, 2, 80.0, false, 0);
    
    student.promoteToNextCourse();
    EXPECT_EQ(student.getCourse(), 3);
}

TEST(StudentMathTest, CalculatesScholarshipAndExcellence) {
    Student student(1, 2, 100.0, false, 0);

    EXPECT_TRUE(student.isExcellentStudent());
    EXPECT_TRUE(student.canReceiveScholarship());
}

TEST(StudentAbsencesTest, IncrementsAbsencesCorrectly) {
    Student student(1, 3, 75.0, false, 5);

    student.addAbsence();
    student.addAbsence();
    EXPECT_EQ(student.getAbsences(), 7);
}