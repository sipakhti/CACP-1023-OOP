



// WEAK RELATIONSHIP
// Aggregation
// Aggregation is a relationship in which a single object is composed of other objects.
// But the objects are not owned by the object.

#include <iostream>
#include <string>

using namespace std;




template <typename T>
class LinkedList{

    class Node{
        public:
        T data;
        Node* next;
    
        Node(T d){
            data = d;
            next = NULL;
        }

        ~Node(){
            cout << "Node destroyed" << endl;
        }
    };

    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        cout << "LinkedList destroyed" << endl;
    }

    void add(T data){
        Node* node = new Node(data);
        if (head == nullptr){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }

    void deleteNode(T data){
        Node* temp = head;
        Node* prev = nullptr;
        while(temp != nullptr){
            if(temp->data == data){
                if(prev == nullptr){
                    head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // index operator
    T& operator[](int index){
        if index >= size || index < 0{
            return nullptr;
        } 
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }

    // size
    int getSize(){
        return size;
    }
};

class Employee
{
public:
    string name;
    int age;
    int id;
    Employee()
    {
        name = "";
        age = 0;
        id = 0;
    }
    Employee(string _name, int _age, int _id)
    {
        name = _name;
        age = _age;
        id = _id;
    }
    ~Employee()
    {
        if (name != "")
            cout << "Employee " << name << " destroyed" << endl;
        else
            cout << "Employee destroyed" << endl;
    }
};

ostream& operator<<(ostream& os, const Employee& emp){
    os << "Name: " << emp.name << endl;
    os << "Age: " << emp.age << endl;
    os << "ID: " << emp.id << endl;
    return os;
}

class University
{
    string name;
    string location;
    LinkedList<Employee> employees;
    size_t numOfEmployees;
public:

    University()
    {
        name = "";
        location = "";
        numOfEmployees = 0;
    }
    University(string _name, string _location, size_t _numOfEmployees)
    {
        name = _name;
        location = _location;
        numOfEmployees = _numOfEmployees;
    }

    ~University()
    {
        cout << name << " destroyed" << endl;
    }
};

