#pragma once

// Шаблон класу з двома незалежними параметрами типу
template <typename NameType, typename ValueType>
class NamedRecord {
private:
    NameType name_;
    ValueType value_;

public:
    NamedRecord() : name_(), value_() {}

    // Конструктор з параметрами
    NamedRecord(const NameType& name, const ValueType& value) 
        : name_(name), value_(value) {}

        NameType getName() const { return name_; }
    ValueType getValue() const { return value_; }

    void setName(const NameType& name) { name_ = name; }
    void setValue(const ValueType& value) { value_ = value; }
};