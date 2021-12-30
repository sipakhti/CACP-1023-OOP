#include <iostream>
#include <string.h>
using namespace std;

namespace stringManipulation {
    char* copyStr(char* source, char* target){
        if (target != nullptr)
            delete[] target;
        int size = strlen(source);
        target = new char[size + 1];
        for (size_t i = 0; i < size; i++)
            target[i] = source[i];
        target[size] = '\0';
        return target;          
    }
}

// Person , Student , Professor
class Person
{
    private:
        char* name;
        int age;

    public:
    Person(char* name, int age){
        setName(name);
        setAge(age);
        cout << "Person constructor" << endl;
    };
    ~Person(){
        if (name)
            delete[] name;
        cout << "Person destructor" << endl;
    };
    // copy constructor
    Person(const Person& other){
        name = stringManipulation::copyStr(other.name, nullptr);
        age = other.age > 0 ? other.age : 0;
        cout << "Person copy constructor" << endl;
    }
    // set Name
    void setName(char* name){
        this->name = stringManipulation::copyStr(name, this->name);
    }
    // get Name
    char* getName() const {
        return stringManipulation::copyStr(name, nullptr);
    }
    // set Age
    void setAge(int age){
        this->age = age > 0 ? age : 0;
    }
    // get Age
    int getAge() const {
        return age;
    }
};

class Student : public Person
{
    private: 
        int id;
        float gpa;
    public:
    Student(char* name, int age, int id, float gpa) : Person(name, age){
        setId(id);
        setGpa(gpa);
        cout << "Student constructor" << endl;
    };
    ~Student(){
        cout << "Student destructor" << endl;
    };
    // copy constructor
    Student(const Student& other) : Person(other){
        setId(other.id);
        setGpa(other.gpa);
        cout << "Student copy constructor" << endl;
    }
    // set Id
    void setId(int id){
        this->id = id > 0 ? id : 0;
    }
    // get Id
    int getId() const {
        return id;
    }
    // set GPA
    void setGpa(float gpa){
        this->gpa = gpa > 0 ? gpa : 0;
    }
    // get GPA
    float getGpa() const {
        return gpa;
    }
};


int main()
{
    Student s1("Ahmed", 20, 1, 3.5);
    Student s2(s1);
    cout << "Name: " << s2.getName() << endl;
    cout << "Age: " << s2.getAge() << endl;
    cout << "Id: " << s2.getId() << endl;
    cout << "GPA: " << s2.getGpa() << endl;
    system("pause");
    return 0;
}

