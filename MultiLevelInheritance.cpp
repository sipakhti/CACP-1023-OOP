#include <iostream>
#include <string.h>
using namespace std;

class Animal {
    int age;
    public:
    Animal(int age) {
        this->age = age;
        cout << "Animal constructor" << endl;
    }
    ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Mammal : public Animal {
    int weight;
    public:
    Mammal(int age, int weight) : Animal(age) {
        this->weight = weight;
        cout << "Mammal constructor" << endl;
    }
    ~Mammal() {
        cout << "Mammal destructor" << endl;
    }
};

class Cat : public Mammal {
    int lives;
    public:
    Cat(int age, int weight, int lives) : Mammal(age, weight) {
        this->lives = lives;
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