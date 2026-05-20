#include "Department.hpp"
#include <cstring>

Department::Department() : name("Unnamed department"), courseCount(0), professorCount(0) {
    for(int i = 0; i < MAX_COURSE; ++i) {
        courses[i] = nullptr;
    }
    for(int i = 0; i < MAX_PROFESSOR; ++i) {
        professors[i] = nullptr;
    }

}

Department::Department(const char* name) : name(name), courseCount(0), professorCount(0) {
    for(int i = 0; i < MAX_COURSE; ++i) {
        courses[i] = nullptr;
    }
    for(int i = 0; i < MAX_PROFESSOR; ++i) {
        professors[i] = nullptr;
    }

}

const char* Department::getName() const {
    return name;
}

int Department::getCourseCount() const {
    return courseCount;
}
int Department::getProfessorCount() const {
    return professorCount;
}
const Course* Department::getCourseAt(int index) const{
    if (index < 0 || index >= courseCount) {
        return nullptr;
    }
    return courses[index];
}
const Professor* Department::getProfessorAt(int index) const {
    if (index < 0 || index >= professorCount) {
        return nullptr;
    }
    return professors[index];
}

bool Department::addCourse(Course& course) {
    if (courseCount >= MAX_COURSE || hasCourse(course.getTitle())) {
        return false;
    }
    courses[courseCount] = &course;
    ++courseCount;
    return true;
}

bool Department::addProfessor(Professor& professor) {
    if (professorCount >= MAX_PROFESSOR || hasProfessor(professor.getName())) {
        return false;
    }
    professors[professorCount] = &professor;
    professorCount++;
    return true;
}

bool Department::hasCourse(const char* title) const {
    for (int i = 0; i < courseCount; ++i) {
        if(courses[i] != nullptr && std::strcmp(courses[i]->getTitle(), title) == 0) {
            return true;
        }
    }
    return false;
}

bool Department::hasProfessor(const char* professorName) const {
    for(int i = 0; i < professorCount; ++i) {
        if (professors[i] != nullptr && std::strcmp(professors[i]->getName(), professorName) == 0) {
            return true;
        }
    }
    return false;
}

bool Department::removeCourse(const char* title) {
    for(int i = 0; i < courseCount; ++i) {
        if(std::strcmp(courses[i]->getTitle(), title) == 0) {
            for (int j = i; j < courseCount - 1; ++j) {
                courses[j] = courses[j + 1];
            }
            courses[courseCount - 1] = nullptr;
            courseCount--;
            return true;
        }
    }
    return false;
}

bool Department::removeProfessor(const char* professorName) {
    for (int i = 0; i < professorCount; ++i) {
        if (std::strcmp(professors[i]->getName(), professorName) == 0) {
            for (int j = i; j < professorCount - 1; ++j) {
                professors[j] = professors[j + 1];
            }
            professors[professorCount - 1] = nullptr;
            professorCount--;
            return true;
        }
    }
    return false;
}