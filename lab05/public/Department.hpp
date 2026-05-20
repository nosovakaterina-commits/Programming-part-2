#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP

#include "Course.hpp"
#include "Professor.hpp"

class Department {
    private:
    static const int MAX_COURSE = 12;
    static const int MAX_PROFESSOR = 10;

    const char* name;
    Course* courses[MAX_COURSE];
    Professor* professors[MAX_PROFESSOR];
    int courseCount;
    int professorCount;

    public:
    Department();
    Department(const char* name);

    const char* getName () const;
    int getCourseCount() const;
    int getProfessorCount() const;
    const Course* getCourseAt(int index) const;
    const Professor* getProfessorAt(int index) const;

    bool addCourse(Course& course);
    bool addProfessor(Professor& professor);
    bool hasCourse(const char* title) const;
    bool hasProfessor(const char* professorName) const;
    bool removeCourse(const char* title);
    bool removeProfessor(const char* name);

};
#endif