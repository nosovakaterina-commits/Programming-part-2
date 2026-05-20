#ifndef Student_HPP
#define Student_HPP

class Student {
    public:
    Student();
    Student(const char* name, int id, int course, double averageGrade, bool scholarship, int absences);

    const char* getName() const;
    int getId() const;
    int getCourse() const;
    double getAverageGrade() const ;
    bool getScholarship() const;
    int getAbsences() const;

    void setId(int value);
    void setCourse(int value);
    void setAverageGrade(double value);
    void setScholarship(bool value);
    void setAbsences(int value);

    void promoteToNextCourse();
    void updateAverageGrade(double value);
    bool isExcellentStudent() const;
    bool canReceiveScholarship() const;
    void addAbsence();

    private:
    const char* name;
    int id;
    int course;
    double averageGrade;
    bool scholarship;
    int absences;
};
#endif