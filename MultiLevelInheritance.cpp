#include <iostream>
#include <string.h>
using namespace std;

class Animal {
    int age;
    public:
    Animal(int _age) {
        this->age = _age;
        cout << "Animal constructor" << endl;
    }
    ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Mammal : public Animal {
    int weight;
    public:
    Mammal(int _age, int _weight) : Animal(_age) {
        this->weight = _weight;
        cout << "Mammal constructor" << endl;
    }
    ~Mammal() {
        cout << "Mammal destructor" << endl;
    }
};

class Cat : public Mammal {
    int lives;
    public:
    Cat(int _age, int _weight, int _lives) : Mammal(_age, _weight) {
        this->lives = _lives;
        cout << "Cat constructor" << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

int main() {
    Cat* cat = new Cat(2, 3, 4);
    delete cat;
    system("pause");
    return 0;
}