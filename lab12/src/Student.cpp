#include "Student.h"

// Конструктор за замовчуванням
Student::Student() : id_(0), name_("") {}

// Конструктор з параметрами
Student::Student(int id, const std::string& name) : id_(id), name_(name) {}

int Student::getId() const { return id_; }
std::string Student::getName() const { return name_; }
void Student::setId(int id) { id_ = id; }
void Student::setName(const std::string& name) { name_ = name; }