#include "Student.hpp"

Student::Student(int id, int course, double averageGrade, bool scholarship, int absences)
: id(id),
course(course > 0 && course <= 4 ? course : 1),
averageGrade(averageGrade >= 0 && averageGrade <= 100 ? averageGrade : 0),
scholarship(scholarship),
absences(absences >= 0 ? absences : 0 ) {}

int Student::getId() const {
    return id;
}
int Student::getCourse() const {
    return course;
}
double Student::getAverageGrade() const {
    return averageGrade;
}
bool Student::getScholarship() const {
    return scholarship;
}
int Student::getAbsences() const {
    return absences;
}

void Student::setId(int value) {
    id = value;
}
void Student::setCourse(int value) {
    if (value >= 1 && value <= 4) {
        course = value;
    }
}
void Student::setAverageGrade(double value) {
    if (value >= 0 && value <= 100) {
        averageGrade = value;
    }
}
void Student::setScholarship(bool value) {
    scholarship = value;
}
void Student::setAbsences(int value) {
    if (value >= 0) {
        absences = value;
    }
}

void Student::promoteToNextCourse() {
    if (course < 4) {
        course ++;
    }
}
void Student::updateAverageGrade(double value) {
    setAverageGrade(value);
}
bool Student::isExcellentStudent() const {
    return averageGrade >= 90.0;
}
bool Student::canReceiveScholarship() const {
    return (averageGrade >= 75.0 && absences <= 50);
}
void Student::addAbsence() {
    absences++;
}