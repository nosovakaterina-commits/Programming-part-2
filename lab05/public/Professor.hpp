#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

class Professor {
    public:
    Professor();
    Professor(const char* name, double averageSalary, const char* courseTitle);

    const char* getName() const;
    double getAverageSalary() const ;
    const char* getCourseTitle() const;

    void setAverageSalary(double value);
    void setCourseTitle(const char* newCourseTitle);

    private:
    const char* name;
    double averageSalary;
    const char* courseTitle;
};
#endif