#pragma once
#include <string>

class Student {
private:
    int id_;
    std::string name_;

public:
    Student();
    Student(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    void setId(int id);
    void setName(const std::string& name);
};