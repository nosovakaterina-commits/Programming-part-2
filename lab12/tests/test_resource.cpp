#include <gtest/gtest.h>
#include "Student.h"
#include "Student_array.h"
#include "Simple_ptr.h"

// 1. Тест конструктора та базового доступу до елементів
TEST(StudentArrayTest, InitializerAndAccess) {
    Student_array arr(2);
    arr.at(0) = Student(1, "Katerina");
    arr.at(1) = Student(2, "Alex");

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr.at(0).getName(), "Katerina");
    EXPECT_EQ(arr.at(1).getId(), 2);
}

// 2. Тест глибокого копіювання
TEST(StudentArrayTest, CopyConstructor) {
    Student_array original(1);
    original.at(0) = Student(10, "Mary");

    // Викликаємо конструктор копіювання
    Student_array copy = original;

    // Перевіряємо, що дані однакові
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.at(0).getName(), "Mary");

    // Змінюємо копію і перевіряємо, що оригінал НЕ змінився
    copy.at(0).setName("NewName");
    EXPECT_EQ(original.at(0).getName(), "Mary");
    EXPECT_EQ(copy.at(0).getName(), "NewName");
}

// 3. Тест семантики переміщення
TEST(StudentArrayTest, MoveConstructor) {
    Student_array original(1);
    original.at(0) = Student(5, "John");

    // Переміщуємо дані в новий об'єкт
    Student_array moved = std::move(original);

    EXPECT_EQ(moved.size(), 1);
    EXPECT_EQ(moved.at(0).getName(), "John");
    EXPECT_EQ(original.size(), 0); // Старий об'єкт має залишитись порожнім
}

// 4. Тест перевірки меж масиву 
TEST(StudentArrayTest, OutOfBoundsException) {
    Student_array arr(2);
    
    EXPECT_THROW(arr.at(5), std::out_of_range);
    EXPECT_THROW(arr.at(2), std::out_of_range);
}

// 5. Тест кастомного розумного вказівника
TEST(SimplePtrTest, BasicUsage) {
    Simple_ptr<Student> ptr(new Student(99, "TestStudent"));
    
    EXPECT_EQ(ptr->getId(), 99);
    EXPECT_EQ((*ptr).getName(), "TestStudent");
}