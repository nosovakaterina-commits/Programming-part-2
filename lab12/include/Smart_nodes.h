#pragma once
#include <memory>
#include <string>
#include "Student.h"

class Smart_nodes
{
public:
    std::string node_name;
    std::shared_ptr<Student> student;
    std::shared_ptr<Smart_nodes> next;
    std::weak_ptr<Smart_nodes> prev;

    Smart_nodes(const std::string &name, std::shared_ptr<Student> s);
    ~Smart_nodes();
};