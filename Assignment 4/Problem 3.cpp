#include <iostream>
#include <string.h>

using namespace std;

class Person {
    mutable char* name;
    mutable char* phone;
    mutable char* email;
    mutable int age;

    protected:
    char* copyStr(const char* source, char* target) const {
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
    Person(char* _name = nullptr, char* _phone = nullptr, char* _email = nullptr, int _age = 0) : name(nullptr), phone(nullptr), email(nullptr) {
        setName(_name);
        setPhone(_phone);
        setEmail(_email);
        setAge(_age);
    }

    // copy constructor
    Person(const Person& other) : name(nullptr), phone(nullptr), email(nullptr) {
        setName(other.name);
        setPhone(other.phone);
        setEmail(other.email);
        setAge(other.age);
    }

    // destructor
    ~Person() {
        delete[] name;
        delete[] phone;
        delete[] email;
    }

    void setName(char* _name) const {
        name = copyStr(_name, name);
    }

    void setPhone(char* _phone) const{
        phone = copyStr(_phone, phone);
    }

    void setEmail(char* _email) const{
        email = copyStr(_email, email);
    }

    void setAge(size_t _age) const {
        age = _age;
    }

    string getName() const {
        char* temp = nullptr;
        return copyStr(name, temp);
    }

    string getPhone() const {
        char* temp = nullptr;
        return copyStr(phone, temp);
    }

    string getEmail() const {
        char* temp = nullptr;
        return copyStr(email, temp);
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
    mutable char* registrationID;
    mutable char* department;
    mutable int completedCredits;

    public:
    Student(char* _regID, char* _department, size_t _completedCredits, char* name, char* phone, char* email, size_t age) : Person(name, phone, email, age) , registrationID(nullptr), department(nullptr) {
        setRegistrationID(_regID);
        setDepartment(_department);
        setCompletedCredits(_completedCredits);
    }

    Student(const Student& other) : Person(other), registrationID(nullptr), department(nullptr) {
        setRegistrationID(other.registrationID);
        setDepartment(other.department);
        setCompletedCredits(other.completedCredits);
    }

    ~Student() {
        delete[] registrationID;
        delete[] department;
    }

    void setRegistrationID(char* _regID) const {
        registrationID = copyStr(_regID, registrationID);
    }

    void setDepartment(char* _dept) const {
        department = copyStr(_dept, department);
    }

    void setCompletedCredits(size_t _credits) const {
        completedCredits = _credits;
    }

    char* getRegistrationID() const {
        char* temp = nullptr;
        return copyStr(registrationID, temp);
    }

    char* getDepartment() const {
        char* temp = nullptr;
        return copyStr(department, temp);
    }

    int getCompletedCredits() const {
        return completedCredits;
    }

    bool study(char* course) const {
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
            setRegistrationID(other.registrationID);
            setDepartment(other.department);
            setCompletedCredits(other.completedCredits);
        }
        return *this;
    }
    // -------------------------------------------------- END OF OPERATORS -------------------------------------------------- //

};

class Teacher : public Person {
    mutable char* staffID;
    mutable double salary;

    public: 
    Teacher(char* name, char* phone, char* email, int age, char* staffID, double _salary) : Person(name, phone, email, age), staffID(nullptr) {
        setStaffID(staffID);
        setSalary(_salary);
    }

    Teacher(const Teacher& other) : Person(other), staffID(nullptr) {
        setStaffID(other.staffID);
        setSalary(other.salary);
    }

    ~Teacher() {
        delete[] staffID;
    }

    void setStaffID(char* _staffID) const {
        staffID = copyStr(_staffID, staffID);
    }

    char* getStaffID() const {
        char* temp = nullptr;
        return copyStr(staffID, temp);
    }

    void setSalary(double _salary) const {
        salary = _salary > 0 ? _salary : 0;
    }

    double getSalary() const {
        return salary;
    }

    bool teach(char* course) const {
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
            setStaffID(other.staffID);
            setSalary(other.salary);
        }
        return *this;
    }    
    // -------------------------------------------------- END OF OPERATORS -------------------------------------------------- //
};

ostream& operator<<(ostream& os, const Person& person){
    os << "Name: " << person.getName() << endl;
    os << "Phone: " << person.getPhone() << endl;
    os << "Email: " << person.getEmail() << endl;
    os << "Age: " << person.getAge() << endl;
    return os;
}

ostream& operator<<(ostream& os, const Student& student){
    os << (Person)student;
    os << "Registration ID: " << student.getRegistrationID() << endl;
    os << "Department: " << student.getDepartment() << endl;
    os << "Completed Credits: " << student.getCompletedCredits() << endl;
    return os;
}

ostream& operator<<(ostream& os, const Teacher& teacher){
    os << (Person)teacher;
    os << "Staff ID: " << teacher.getStaffID() << endl;
    os << "Salary: " << teacher.getSalary() << endl;
    return os;
}


int main() {
    Student s1("12345", "CS", 3, "John", "123456789", "test@aabc.com", 20);
    Teacher t1("Jane", "123456789", "test.com", 20, "12345", 2545454);
    cout << s1 << endl;
    cout << t1 << endl;
    getchar();
    return 0;
}