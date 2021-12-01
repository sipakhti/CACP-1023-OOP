#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
    const double PI = M_PI;
    double radius;
    inline static int count = 0; //to count the number of circles instantiated
public:

    // -------------------------------------------------------------CONSTRUCTORS-------------------------------------------------------------//
    /**
     * @brief Construct a new Circle object
     * 
     * @param r radius of the circle (default is 0)
     */
    Circle(double r=0){
        radius = r > 0 ? r : 0;
        cout << "Constructor Called!" << endl;
        Circle::incrementCount();
    };

    Circle(const Circle& circle){
        radius = circle.radius;
        cout << "Copy Constructor Called!" << endl;
        Circle::incrementCount();
    };

     //------------------------------------------------------DESTRUCTOR-----------------------------------------------------------------------//
    ~Circle(){
        cout << "Destructor Called!" << endl;
        Circle::decrementCount();
    };

    /**
     * @brief prints the area of the circle
     * 
     */
    void area(){
        cout << "Approximate Area =~ " << radius * radius * PI << endl;
    };

    
    double getRadius(){
        return radius;
    };

    //------------------------------------------------------OVERLOADED OPERATORS------------------------------------------------------//

    // Overloaded assignment operator
    Circle& operator=(const Circle& circle){
        cout << "Assignment Operator Called!" << endl;
        radius = circle.radius;
        return *this;
    };
    // Overloaded addition operator
    Circle& operator+=(const double _radius){
        radius += _radius;
        return *this;
    };
    // Overloaded < operator
    bool operator<(const Circle& c2){
        return radius < c2.radius;
    };
    // Overloaded post increment operator
    Circle operator++(int){
        Circle temp = *this;
        radius++;
        return temp;
    };
    // Overloaded pre increment operator
    Circle& operator++(){
        ++radius;
        return *this;
    };
    // Overloaded post decrement operator
    Circle operator--(int){
        Circle temp = *this;
        radius--;
        return temp;
    };
    // Overloaded pre decrement operator
    Circle& operator--(){
        --radius;
        return *this;
    };
    // Overloaded equality operator
    Circle operator==(const Circle& c2){
        return radius == c2.radius;
    };
    // -------------------------------------------------------------OVERLOADED STREAM OPERATORS------------------------------------------------------//
    friend ostream& operator<<(ostream& out, Circle& circle){
        out << "Radius: " << circle.radius << endl;
        return out;
    };
    friend istream& operator>>(istream& in, Circle& circle){
        in >> circle.radius;
        return in;
    };

    //------------------------------------------------------END OF OVERLOADED OPERATORS------------------------------------------------------//
    //------------------------------------------------------STATIC METHODS------------------------------------------------------//
    /**
     * @brief prints the number of circles instantiated
     */
    static void noOfCircles(){
        cout << "No of circles instantiated: " << count << endl;
    };
    //method to increment the count
    /**
     * @brief increments the count of circles instantiated
     * 
     */
    static void incrementCount(){
        count++;
    };
    //method to decrement the count
    /**
     * @brief decrements the count of circles instantiated
     * 
     */
    static void decrementCount(){
        count--;
    };
    //------------------------------------------------------END OF STATIC METHODS------------------------------------------------------//


};

// istream& operator>>(istream& in, Circle& circle){
//     in >> circle.getRadius();
//     return in;
// };


int main()
{
    // instantiate 4 circles
    Circle obj1,obj2,obj3,obj4;
    // reads the radius of the circle from the user
    cin >> obj1 >> obj2 >> obj3 >> obj4; //If we make >> and << operator non-returning?
    // if we make the >> and << operator non-returning, we can't use the above statements
    // the reason is that the >> and << operators also has itself as a parameter
    // so when we try to return void, it will try to pass the return value of the >> and << operator
    // which is void, so it will throw an error
    cout << obj1 << obj2 << obj3 << obj4;
    Circle::noOfCircles();
    obj4 = obj4;
    obj1 += 1.5;//Do check if we do not return circle by reference than what happens?
    // i checked if we can use a non-returning operator and still it worked fine
    obj1.area();
    ++++obj1; //Do check if we do not return circle by reference than what happens?
    obj1.area();
    cout << (obj1 < obj2 ? "True" : "False") << endl;
    return 0;
}
