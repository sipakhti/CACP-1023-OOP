#include <iostream>
#include <string.h>

using namespace std;

class GeometricShape {
    private:
        mutable char* shapeName;

        void copyStr(const char* source, char* target) const {
            if (source == nullptr) 
                target = nullptr;
            else {
                int size = strlen(source);
                if (target == nullptr)
                    target = new char[size + + 1];
                else
                    delete[] target;
                
                for (size_t i = 0; i < size; i++)
                    target[i] = source[i];
                target[size] = '\0';
            }
        }
    public:
    GeometricShape(const char* _shapeName = nullptr) {
        setName(_shapeName);
    }

    GeometricShape(const GeometricShape& other) {
        setName(other.shapeName);
    }

    void setName(const char* _shapeName) const {
        copyStr(_shapeName, shapeName);
    }

    char* getName() const {
        char* temp = nullptr;
        copyStr(shapeName, temp);
        return temp;
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
        cout << "Area of " << getName() << " is " << getArea() << endl;
    }
};

