#include <iostream>
#include <string.h>

using namespace std;

class GeometricShape {
    protected:
        mutable char* shapeName;

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
    GeometricShape(const char* _shapeName = nullptr) : shapeName(nullptr){
        setName(_shapeName);
    }

    GeometricShape(const GeometricShape& other) {
        setName(other.shapeName);
    }

    ~GeometricShape() {
        if (shapeName != nullptr)
            delete[] shapeName;
    }

    GeometricShape& operator=(const GeometricShape& other) {
        setName(other.shapeName);
        cout << "Assignment operator called" << endl;
        return *this;
    }

    void setName(const char* _shapeName) const {
        shapeName = copyStr(_shapeName, shapeName);
    }
    
};

class Trigon : public GeometricShape {
    private:
        mutable double base;
        mutable double height;
        mutable double prependicular;

        double getArea() const {
            return (base * height) / 2;
        }

    public:
    // default constructor
    Trigon() : GeometricShape() {
        base = 1.0;
        height = 1.0;
        prependicular = 1.0;
    }

    // parameterized constructor
    Trigon(double _base, double _height, double _prependicular, const char* _shapeName = nullptr) : GeometricShape(_shapeName) {
        setBase(_base);
        setHeight(_height);
        setPrependicular(_prependicular);
    }

    // copy constructor
    Trigon(const Trigon& other) : GeometricShape(other) {
        setBase(other.base);
        setHeight(other.height);
        setPrependicular(other.prependicular);
    }

    void setBase(double _base) const {
        base = _base;
    }

    void setHeight(double _height) const {
        height = _height;
    }

    void setPrependicular(double _prependicular) const {
        prependicular = _prependicular;
    }

    double getBase() const {
        return base;
    }

    double getHeight() const {
        return height;
    }

    double getPrependicular() const {
        return prependicular;
    }

    void displayArea() const {
        cout << "Area of " << shapeName << " is " << getArea() << endl;
    }
};

// demo main for testing
int main() {
    Trigon t1;
    t1.setName("Triangle");
    t1.setBase(2.0);
    t1.setHeight(3.0);
    t1.setPrependicular(4.0);
    t1.displayArea();
    Trigon t2(20.0, 15.0, 78.0, "Triangle 2");
    t2.displayArea();
    Trigon t3;
    t3 = t2;
    system("pause");
    return 0;
}