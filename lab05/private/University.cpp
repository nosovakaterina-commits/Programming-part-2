#include "University.hpp"
#include <cstring>

University::University() : name("Unnamed univesity"), departmentCount(0) {
    for (int i = 0; i < MAX_DEPARTMENT; ++i) {
        departments[i] = nullptr;
    }
}

University::University(const char* name) : name (name), departmentCount(0) {
    for (int i = 0; i <MAX_DEPARTMENT; ++i) {
        departments[i] = nullptr;
    }
}

const char* University::getName() const {
    return name;
}

int University::getDepartmentCount() const {
    return departmentCount;

}

const Department* University::getDepartmentAt(int index) const {
    if (index < 0 || index >= departmentCount) {
        return nullptr;
    }
    return departments[index];
}

bool University::hasDepartment(const char* departmentName) const{
    for (int i = 0; i < departmentCount; ++i) {
        if (departments[i] != nullptr && std::strcmp(departments[i]->getName(), departmentName) == 0) {
            return true;
        }
    }
    return false;
}

bool University::addDepartment(Department& department) {
    if (departmentCount >= MAX_DEPARTMENT || hasDepartment(department.getName())) {
        return false;
    }
    departments[departmentCount] = &department;
    ++departmentCount;
    return true;
}