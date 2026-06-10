#include "record.hpp"

// Конструктор за замовчуванням
Record::Record() : id(0), passengerName(""), destination(""), ticketPrice(0.0) {}

// Параметризований конструктор
Record::Record(int p_id, std::string name, std::string dest, double price)
    : id(p_id), passengerName(std::move(name)), destination(std::move(dest)), ticketPrice(price) {}

// Реалізація для SharedRecord
SharedRecord::SharedRecord(int p_id, std::string name, std::string dest, double price)
    : id(p_id), passengerName(std::make_shared<std::string>(std::move(name))), destination(std::move(dest)), ticketPrice(price) {}

// Реалізація для UniqueRecord
UniqueRecord::UniqueRecord(int p_id, std::string name, std::string dest, double price)
    : id(p_id), passengerName(std::make_unique<std::string>(std::move(name))), destination(std::move(dest)), ticketPrice(price) {}