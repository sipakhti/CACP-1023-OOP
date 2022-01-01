#include <iostream>
#include <string>

using namespace std;

class GraduateCourse {
    string COURSE_ID;
    string COURSE_NAME;
    int CREDIT_HOURS;
    double COURSE_FEE;

    public:
    GraduateCourse(string course_id, string course_name, int credit_hours, double course_fee) : COURSE_ID(course_id), COURSE_NAME(course_name), CREDIT_HOURS(credit_hours), COURSE_FEE(course_fee) {};

    string getCourseId() const {
        return COURSE_ID;
    }

    string getCourseName() const {
        return COURSE_NAME;
    }

    int getCreditHours() const {
        return CREDIT_HOURS;
    }

    double getCourseFee() const {
        return COURSE_FEE;
    }
};

class ResearchCourse : public GraduateCourse {
    mutable double experimentFee;

    public:
    ResearchCourse(string course_id, string course_name, int credit_hours, double course_fee, double experiment_fee) : GraduateCourse(course_id, course_name, credit_hours, course_fee) {
        setExperimentFee(experiment_fee);
    };

    void setExperimentFee(double experiment_fee) const {
        experimentFee = experiment_fee > 0 ? experiment_fee : 1.0;
    }

    double getExperimentFee() const {
        return experimentFee;
    }

    void display() const {
        cout << "Course ID: " << getCourseId() << endl;
        cout << "Course Name: " << getCourseName() << endl;
        cout << "Credit Hours: " << getCreditHours() << endl;
        cout << "Course Fee: " << getCourseFee() << endl;
        cout << "Experiment Fee: " << getExperimentFee() << endl;
    }

    void totalFee() const {
        cout << "Total Fee: " << getCourseFee() + getExperimentFee() << endl;
    }
};