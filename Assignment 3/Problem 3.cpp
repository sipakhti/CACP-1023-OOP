#include <iostream>
#include <string>

using namespace std;

class Person {
    mutable string name;
    mutable string phone;
    mutable string email;
    mutable int age;

    public:
    Person(string _name = nullptr, string _phone = nullptr, string _email = nullptr, int _age = 0){
        setName(_name);
        setPhone(_phone);
        setEmail(_email);
        setAge(_age);
    }

    // copy constructor
    Person(const Person& other) {
        setName(other.name);
        setPhone(other.phone);
        setEmail(other.email);
        setAge(other.age);
    }

    void setName(string _name) const{
        name = _name;
    }

    void setPhone(string _phone) const{
        phone = _phone;
    }

    void setEmail(string _email) const{
        email = _email;
    }

    void setAge(size_t _age) const{
        age = _age;
    }

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    string getEmail() const {
        return email;
    }

    int getAge() const {
        return age;
    }

    bool walk() const {
        cout << name << " is now walking indefinetly!" << endl;
        return true;
    }

    bool walk(size_t steps) const {
        cout << name << " is now walking " << steps << " steps!" << endl;
        return true;
    }

    // -------------------------------------------------- OPERATORS -------------------------------------------------- //
    // comparison operators
    bool operator==(const Person& other) const{
        return (name == other.name && phone == other.phone && email == other.email && age == other.age);
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    // assignment operator
    Person& operator=(const Person& other) {
        if (this != &other) {
            setName(other.name);
            setPhone(other.phone);
            setEmail(other.email);
            setAge(other.age);
        }
        return *this;
    }

    // -------------------------------------------------- END OF OPERATORS -------------------------------------------------- //


};

class Student : public Person {
    string registrationID;
    mutable string department;
    mutable int completedCredits;

    public:
    Student(string _regID, string _department, size_t _completedCredits, string name, string phone, string email, size_t age) : Person(name, phone, email, age) , registrationID(_regID){
        setDepartment(_department);
        setCompletedCredits(_completedCredits);
    }

    void setDepartment(string _dept) const {
        department = _dept;
    }

    void setCompletedCredits(size_t _credits) const {
        completedCredits = _credits;
    }

    string getRegistrationID() const {
        return registrationID;
    }

    string getDepartment() const {
        return department;
    }

    int getCompletedCredits() const {
        return completedCredits;
    }

    bool study(string course) const {
        cout << getName() << " is now studying " << course << endl;
        return true;
    }

    // -------------------------------------------------- OPERATORS -------------------------------------------------- //
    // comparison operators

    bool operator==(const Student& other) const {
        return ((Person) *this) == other && registrationID == other.registrationID;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    // assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            (Person) *this = other;
            registrationID = other.registrationID;
            department = other.department;
            completedCredits = other.completedCredits;
        }
        return *this;
    }
    // -------------------------------------------------- END OF OPERATORS -------------------------------------------------- //

};

class Teacher : public Person {
    string staffID;
    mutable double salary;

    public: 
    Teacher(string name, string phone, string email, int age, string staffID, double _salary) : Person(name, phone, email, age), staffID(staffID) {
        setSalary(salary);
    }

    string getStaffID() const {
        return staffID;
    }

    void setSalary(double _salary) const {
        salary = _salary > 0 ? salary : 0;
    }

    double getSalary() const {
        return salary;
    }

    bool teach(string course) const {
        cout << getName() << " is now teaching " << course << endl;
        return true;
    }

    // -------------------------------------------------- OPERATORS -------------------------------------------------- //
    // comparison operators
    bool operator==(const Teacher& other) const {
        return (Person) *this == other && staffID == other.staffID;
    }

    bool operator!=(const Teacher& other) const {
        return !(*this == other);
    }

    // assignment operator
    Teacher& operator=(const Teacher& other) {
        if (this != &other) {
            (Person) *this = other;
            staffID = other.staffID;
            salary = other.salary;
        }
        return *this;
    }    
    // -------------------------------------------------- END OF OPERATORS -------------------------------------------------- //
};

ostream& operator<<(ostream& os, const Person& p){
    os << "Name: " << p.getName() << endl;
    os << "Phone: " << p.getPhone() << endl;
    os << "Email: " << p.getEmail() << endl;
    os << "Age: " << p.getAge() << endl;
    return os;
}

ostream& operator<<(ostream& os, const Student& s){
    os << (Person)s;
    os << "Registration ID: " << s.getRegistrationID() << endl;
    os << "Department: " << s.getDepartment() << endl;
    os << "Completed Credits: " << s.getCompletedCredits() << endl;
    return os;
}

ostream& operator<<(ostream& os, const Teacher& t){
    os << (Person)t;
    os << "Staff ID: " << t.getStaffID() << endl;
    os << "Salary: " << t.getSalary() << endl;
    return os;
}

