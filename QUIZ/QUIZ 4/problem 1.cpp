
/**
 * @file problem 1.cpp
 * @author Umer Mehmood Khan Rana L1F20ASCS0028
 * @brief Order of Construction and Destruction

Implement the following scenario and show the execution order for construction and destruction of objects in inheritance hierarchy by
 just giving the output statement “class name Construtor called” and “ class name Destructor called” in constructors and destructors 
 of every class. Class AA is serving as the base class. Class BB is publicly inherited from class AA. Class CC is publicly inherited
 from class BB and finally the class DD is publicly inherited from class CC.

In main()
Just instantiate object of DD class and see what happens. Check the order of construction and destruction of the parent and child objects.
 * @version 0.1
 * @date 2022-01-06

 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string.h>

using namespace std;

class AA {
    public:
        AA() {
            cout << "AA Constructor called" << endl;
        }
        ~AA() {
            cout << "AA Destructor called" << endl;
        }
};

class BB : public AA {
    public:
        BB() {
            cout << "BB Constructor called" << endl;
        }
        ~BB() {
            cout << "BB Destructor called" << endl;
        }
};

class CC : public BB {
    public:
        CC() {
            cout << "CC Constructor called" << endl;
        }
        ~CC() {
            cout << "CC Destructor called" << endl;
        }
};

class DD : public CC {
    public:
        DD() {
            cout << "DD Constructor called" << endl;
        }
        ~DD() {
            cout << "DD Destructor called" << endl;
        }
};

int main() {
    DD obj;
    return 0;
}