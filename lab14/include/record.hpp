#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>
#include <memory>

struct Record
{
    int id;
    std::string passengerName;
    std::string destination;
    double ticketPrice;

    Record();
    Record(int p_id, std::string name, std::string dest, double price);
};

// Модифікація із розділеним ресурсом
struct SharedRecord
{
    int id;
    std::shared_ptr<std::string> passengerName;
    std::string destination;
    double ticketPrice;

    SharedRecord(int p_id, std::string name, std::string dest, double price);
};

// Модифікація Move-only
struct UniqueRecord
{
    int id;
    std::unique_ptr<std::string> passengerName;
    std::string destination;
    double ticketPrice;

    UniqueRecord(int p_id, std::string name, std::string dest, double price);

    // Заборона копіювання
    UniqueRecord(const UniqueRecord &) = delete;
    UniqueRecord &operator=(const UniqueRecord &) = delete;

    // Дозвіл переміщення
    UniqueRecord(UniqueRecord &&) noexcept = default;
    UniqueRecord &operator=(UniqueRecord &&) noexcept = default;
};

#endif