#include <gtest/gtest.h>
#include "container_analyzer.hpp"

// Тестування базових алгоритмів обробки даних
TEST(Lab14LogicValidation, ProcessAndFilterData) {
    std::vector<Record> testVec;
    testVec.emplace_back(1, "User1", "Kharkiv", 100.0);
    testVec.emplace_back(2, "User2", "Dnipro", 300.0);
    testVec.emplace_back(3, "User3", "Kharkiv", 150.0);

    // Перевірка пошуку першого елемента
    const Record* res = ContainerAnalyzer::findFirstByDestination(testVec, "Dnipro");
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->passengerName, "User2");

    // Перевірка підрахунку квитків
    EXPECT_EQ(ContainerAnalyzer::countTicketsAbovePrice(testVec, 120.0), 2);

    // Перевірка коректності фільтрації
    std::vector<Record> filtered = ContainerAnalyzer::filterByDestination(testVec, "Kharkiv");
    EXPECT_EQ(filtered.size(), 2);
    EXPECT_EQ(filtered[0].passengerName, "User1");
}

// Тестування смарт-вказівників 
TEST(RecordModificationTest, SmartPointersValidation) {
    // Перевірка SharedRecord
    SharedRecord shared(1, "SharedPassenger", "Kyiv", 200.0);
    EXPECT_EQ(*(shared.passengerName), "SharedPassenger");

    // Перевірка UniqueRecord
    UniqueRecord unique(2, "UniquePassenger", "Lviv", 250.0);
    EXPECT_EQ(*(unique.passengerName), "UniquePassenger");

    // Перевірка операції переміщення для unique_ptr об'єкта
    UniqueRecord movedUnique = std::move(unique);
    EXPECT_EQ(*(movedUnique.passengerName), "UniquePassenger");
}