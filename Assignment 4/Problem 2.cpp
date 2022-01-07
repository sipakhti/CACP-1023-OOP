#include <iostream>
#include <string.h>

using namespace std;

class GraduateCourse {
    private:
    char* courseID;
    char* courseName;
    int creditHours;
    double courseFee;

    char* copyStr(const char* source, char* target) const{
        if (source == nullptr)
            target = nullptr;
        else {
            int size = strlen(source);
            if (target != nullptr)
                delete[] target;

            target = new char[size + 1];
            for (int i = 0; i < size; i++)
                target[i] = source[i];
            target[size] = '\0';
        }
        return target;
    } 
    public:
    GraduateCourse(char* _courseID = nullptr, char* _courseName = nullptr, int _creditHours = 0, double _courseFee = 0.0) : courseID(nullptr), courseName(nullptr) {
        courseID = copyStr(_courseID, courseID);
        courseName = copyStr(_courseName, courseName);
        creditHours = _creditHours > 0 ? _creditHours : 0;
        courseFee = _courseFee > 0 ? _courseFee : 0.0;
    }

    GraduateCourse(const GraduateCourse& other) : courseID(nullptr), courseName(nullptr) {
        courseID = copyStr(other.courseID, courseID);
        courseName = copyStr(other.courseName, courseName);
        creditHours = other.creditHours;
        courseFee = other.courseFee;
    }

    ~GraduateCourse() {
        if (courseID != nullptr)
            delete[] courseID;
        if (courseName != nullptr)
            delete[] courseName;
    }

    char* getCourseID() const {
        char* temp(nullptr);
        return copyStr(courseID, temp);
    }

    char* getCourseName() const {
        char* temp(nullptr);
        return copyStr(courseName, temp);
    }

    int getCreditHours() const {
        return creditHours;
    }

    double getCourseFee() const {
        return courseFee;
    }

    GraduateCourse& operator=(const GraduateCourse& other) {
        courseID = copyStr(other.courseID, courseID);
        courseName = copyStr(other.courseName, courseName);
        creditHours = other.creditHours;
        courseFee = other.courseFee;
        return *this;
    }
};


class ResearchCourse : public GraduateCourse {
    private:
        mutable double experimentFee;

    public:
    ResearchCourse(char* _courseID = nullptr, char* _courseName = nullptr, int _creditHours = 0, double _courseFee = 0.0, double _experimentFee = 0.0) : GraduateCourse(_courseID, _courseName, _creditHours, _courseFee) {
        setExperimentFee(_experimentFee);
    }

    ResearchCourse(const ResearchCourse& other) : GraduateCourse(other) {
        setExperimentFee(other.experimentFee);
    }

    void setExperimentFee(double _experimentFee) const {
        experimentFee = _experimentFee > 0 ? _experimentFee : 0.0;
    }

    void display() const {
        cout << "--------------------------------------------" << endl;
        cout << "Course ID: " << getCourseID() << endl;
        cout << "Course Name: " << getCourseName() << endl;
        cout << "Credit Hours: " << getCreditHours() << endl;
        cout << "Course Fee: " << getCourseFee() << endl;
        cout << "Experiment Fee: " << experimentFee << endl;
        cout << "--------------------------------------------" << endl;
    }

    void totalFee() const {
        cout << "Total Fee: " << getCourseFee() + experimentFee << endl;
    }
};

int main() {
    ResearchCourse course("CSCI", "Computer Science", 3, 5000, 1000);
    course.display();
    course.totalFee();
    course.setExperimentFee(25000);
    course.display();
    course.totalFee();
    getchar();
    return 0;
}