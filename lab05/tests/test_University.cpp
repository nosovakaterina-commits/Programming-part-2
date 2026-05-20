#include <gtest/gtest.h>
#include "University.hpp"

TEST(UniversityTest, StoresReferencesToIndependentObjects) {
    University university("National Technological University");
    Professor professor("Dr. Alexander Ivanov", 45000.0, "Advanced C++");
    Department department("Computer Science");

    EXPECT_TRUE(department.addProfessor(professor));
    EXPECT_TRUE(university.addDepartment(department));
    EXPECT_EQ(university.getDepartmentCount(), 1);
    EXPECT_EQ(department.getProfessorCount(), 1);
    ASSERT_NE(university.getDepartmentAt(0), nullptr);
    ASSERT_NE(department.getProfessorAt(0), nullptr);
    EXPECT_STREQ(university.getDepartmentAt(0)->getName(), "Computer Science");
    EXPECT_STREQ(department.getProfessorAt(0)->getName(), "Dr. Alexander Ivanov");
}

TEST(UniversityTest, CourseCanAddAndRemoveStudentsWithoutOwningTheirLifetime) {
    Course course("Advanced C++");
    Student student("Katerina Nosova", 101, 2, 95.5, true, 2);

    EXPECT_TRUE(course.addStudent(student));
    EXPECT_TRUE(course.hasStudent(101));
    EXPECT_TRUE(student.isExcellentStudent()); // Поведенческий метод: балл 95.5 >= 90.0

    EXPECT_TRUE(course.removeStudent(101));
    EXPECT_FALSE(course.hasStudent(101));
   
    EXPECT_STREQ(student.getName(), "Katerina Nosova");
    EXPECT_EQ(student.getId(), 101);
}

TEST(UniversityTest, DuplicateObjectsAreRejected) {
    University university("NTU Gallery");
    Department department("Modernism");
    Professor professor("Dr. Maria Petrova", 48000.0, "Discrete Mathematics");
    Course course("Discrete Mathematics");
    Student student("Alex Smith", 102, 2, 75.0, false, 0);

    EXPECT_TRUE(university.addDepartment(department));
    EXPECT_FALSE(university.addDepartment(department));

    EXPECT_TRUE(department.addProfessor(professor));
    EXPECT_FALSE(department.addProfessor(professor));

    EXPECT_TRUE(department.addCourse(course));
    EXPECT_FALSE(department.addCourse(course));

    EXPECT_TRUE(course.addStudent(student));
    EXPECT_FALSE(course.addStudent(student));
}