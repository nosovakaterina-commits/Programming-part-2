#include <gtest/gtest.h>
#include <string>
#include "grade_book.h"
#include "named_record.h"
#include "grade_threshold.h"

// Тестування базового шаблону GradeBook для типу int
TEST(GradeBookTest, HandlesIntGrades) {
    GradeBook<int, 3> book;
    
    // Перевірка початкового стану порожньої книги
    EXPECT_EQ(book.count(), 0);
    
    // Перевірка успішного додавання елементів
    EXPECT_TRUE(book.addGrade(70));
    EXPECT_TRUE(book.addGrade(85));
    EXPECT_EQ(book.count(), 2);
    
    // Перевірка коректності збережених даних та розрахунків
    EXPECT_EQ(book.get(0), 70);
    EXPECT_EQ(book.best(), 85);
    EXPECT_DOUBLE_EQ(book.average(), 77.5);
}

// Тестування обмеження ємності масиву
TEST(GradeBookTest, CapacityBoundaries) {
    GradeBook<int, 2> book;
    
    EXPECT_TRUE(book.addGrade(100));
    EXPECT_TRUE(book.addGrade(90));
    EXPECT_FALSE(book.addGrade(80)); 
}

// Тестування генерації винятків для порожньої книги та помилок індексації
TEST(GradeBookTest, ThrowsOnInvalidAccess) {
    GradeBook<double, 5> emptyBook;
    
    EXPECT_THROW(emptyBook.get(0), std::out_of_range);
    EXPECT_THROW(emptyBook.best(), std::runtime_error);
    EXPECT_THROW(emptyBook.average(), std::runtime_error);
}

// Тестування роботи шаблону NamedRecord з двома типами параметрів
TEST(NamedRecordTest, StoresNameAndValue) {
    NamedRecord<std::string, int> record("Ivanov", 95);
    EXPECT_EQ(record.getName(), "Ivanov");
    EXPECT_EQ(record.getValue(), 95);
    
    record.setName("Petrov");
    record.setValue(80);
    EXPECT_EQ(record.getName(), "Petrov");
    EXPECT_EQ(record.getValue(), 80);
}

// Тестування політики меж GradeThreshold та її повної спеціалізації
TEST(GradeThresholdTest, ThresholdValues) {
    // Перевірка значень для базового шаблону (тип int)
    EXPECT_EQ(GradeThreshold<int>::pass(), 60);
    EXPECT_EQ(GradeThreshold<int>::excellent(), 90);
    
    // Перевірка значень для повної спеціалізації (тип double)
    EXPECT_DOUBLE_EQ(GradeThreshold<double>::pass(), 60.0);
    EXPECT_DOUBLE_EQ(GradeThreshold<double>::excellent(), 90.0);
}