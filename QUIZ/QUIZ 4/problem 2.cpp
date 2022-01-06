/**
 * @file problem 2.cpp
 * @author UMER MEHMOOD KAN RANA L1F20ASCS0028
 * @brief You have base class Person which has attributes:

    • name: char*

    • age : int

    You have an Employee class which is publically inherited from Person class. It has attributes:

    • salary : double

    • employeeId : int

    You have another class BaseballPlayer publically inherited from Person class. It has attributes:

    • battingAverage: double

    • totalRuns: int

    Provide the following for all the classes.

    1. Write parameterized constructor with default arguments.

    2. Write separate setter functions for each attribute to set value.

    3. Write separate getter functions for each attribute to get value.

    4. Write a display() function to display the information.

    In main()

    • Make Baseball class object in main and initialize values of name, age, battingAverage and totalRuns using
     base/constructor initialization list and call display() against it
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>

using namespace std;

class Person {
    private:
        mutable char* name;
        mutable int age;

        char* copyStr(const char* source, char* target) const {
            if (source == nullptr) 
                target = nullptr;
            else {
                int size = strlen(source);
                if (target != nullptr)
                    delete[] target;
                
                target = new char[size + 1];
                for (size_t i = 0; i < size; i++)
                    target[i] = source[i];
                target[size] = '\0';
            }
            return target;
        }
    public:
    Person(const char* _name = nullptr, int _age = 0) {
        name = nullptr;
        setName(_name);
        setAge(_age);
    }

    Person(const Person& other) {
        setName(other.name);
        setAge(other.age);
    }

    ~Person() {
        if (name != nullptr)
            delete[] name;
    }

    void setName(const char* _name) const {
        name = copyStr(_name, name);
    }

    char* getName() const {
        char* temp = nullptr;
        temp = copyStr(name, temp);
        return temp;
    }

    void setAge(int _age) const {
        age = _age;
    }

    int getAge() const {
        return age;
    }

    void display() const {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
    }
};

class Employee : public Person {
    mutable double salary;
    mutable int employeeId;

    public:
    Employee(const char* _name = nullptr, int _age = 0, double _salary = 0, int _employeeId = 0) : Person(_name, _age) {
        setSalary(_salary);
        setEmployeeId(_employeeId);
    }

    Employee(const Employee& other) : Person(other) {
        setSalary(other.salary);
        setEmployeeId(other.employeeId);
    }

    void setSalary(double _salary) const {
        salary = _salary > 0 ? _salary : 0;
    }

    double getSalary() const {
        return salary;
    }

    void setEmployeeId(int _employeeId) const {
        employeeId = _employeeId;
    }

    int getEmployeeId() const {
        return employeeId;
    }

    void display() const {
        Person::display();
        cout << "Salary: " << getSalary() << endl;
        cout << "Employee Id: " << getEmployeeId() << endl;
    }
};

class BaseballPlayer : public Person {
    mutable double battingAverage;
    mutable int totalRuns;

    public:
    BaseballPlayer(const char* _name = nullptr, int _age = 0, double _battingAverage = 0, int _totalRuns = 0) : Person(_name, _age) {
        setBattingAverage(_battingAverage);
        setTotalRuns(_totalRuns);
    }

    BaseballPlayer(const BaseballPlayer& other) : Person(other) {
        setBattingAverage(other.battingAverage);
        setTotalRuns(other.totalRuns);
    }

    void setBattingAverage(double _battingAverage) const {
        battingAverage = _battingAverage > 0 ? _battingAverage : 0;
    }

    double getBattingAverage() const {
        return battingAverage;
    }

    void setTotalRuns(int _totalRuns) const {
        totalRuns = _totalRuns > 0 ? _totalRuns : 0;
    }

    int getTotalRuns() const {
        return totalRuns;
    }

    void display() const {
        Person::display();
        cout << "Batting Average: " << getBattingAverage() << endl;
        cout << "Total Runs: " << getTotalRuns() << endl;
    }
};

/**
 * @brief • Make Baseball class object in main and initialize values of name, age, battingAverage and totalRuns using base/constructor initialization list and call display() against it.

• Make Employee class object in main and initialize values of name, age, employeeId and salary using base/constructor initialization list and call display() against it.
 * 
 * @return int 
 */
int main() {
    BaseballPlayer player("Umer", 20, 0.5, 100);
    player.display();
    cout << "-----------------------------" << endl;
    Employee employee("Umer", 20, 50000, 100);
    employee.display();

    return 0;
}