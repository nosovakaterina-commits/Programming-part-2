#include "Smart_nodes.h"
#include <iostream>

Smart_nodes::Smart_nodes(const std::string& name, std::shared_ptr<Student> s) 
    : node_name(name), student(s), next(nullptr) {}

Smart_nodes::~Smart_nodes() {
    std::cout << "[Smart_nodes Destructor] " << node_name << " successfully freed from memory." << std::endl;
}