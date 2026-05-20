#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Department.hpp"

class University {
    private:
    static const int MAX_DEPARTMENT = 8;

    const char* name;
    Department* departments[MAX_DEPARTMENT];
    int departmentCount;

    public:
    University();
    University(const char* name);

    const char* getName() const;
    int getDepartmentCount() const;
    const Department* getDepartmentAt(int index) const;

    bool addDepartment(Department& department);
    bool hasDepartment(const char* departmentName) const;
};
#endif