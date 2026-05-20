#include "Course.hpp"

Course::Course() : title("Unnamed course"), studentCount(0) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        students[i] = nullptr;
    }
}

Course::Course(const char* title) : title(title), studentCount(0) {
    for (int i = 0; i <MAX_STUDENTS; ++i) {
        students[i] = nullptr;
    }
}

const char* Course::getTitle() const {
    return title;
}

int Course::getStudentCount() const {
    return studentCount;

}

const Student* Course::getStudentAt(int index) const {
    if (index < 0 || index >= studentCount) {
        return nullptr;
    }
    return students[index];
}

bool Course::hasStudent(int studentNumber) const{
    for (int i = 0; i < studentCount; ++i) {
        if (students[i] != nullptr && students[i]->getId() == studentNumber) {
            return true;
        }
    }
    return false;
}

bool Course::addStudent(Student& student) {
    if (studentCount >= MAX_STUDENTS || hasStudent(student.getId())) {
        return false;
    }
    students[studentCount] = &student;
    ++studentCount;
    return true;
}

bool Course::removeStudent(int studentNumber) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i] != nullptr && students[i]->getId() == studentNumber) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            students[studentCount - 1] = nullptr;
            studentCount--;
            return true;
        }
    }
    return false; 
}