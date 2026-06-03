#ifndef COURSE_HPP
#define COURSE_HPP

#include "Student.hpp"

class Course {
    private:
    static const int MAX_STUDENTS = 30;

    const char* title;
    Student* students[MAX_STUDENTS];
    int studentCount;

    public:
    Course();
    Course(const char* title);

    const char* getTitle() const;
    int getStudentCount() const;
    const Student* getStudentAt(int index) const;

    bool addStudent(Student& student);
    bool removeStudent(int studentNumber);
    bool hasStudent(int studentNumber) const;
};
#endif