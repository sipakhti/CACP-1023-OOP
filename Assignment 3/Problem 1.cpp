#include <iostream>
#include <string.h>

using namespace std;

class GeometricShape {
    protected:
    mutable string shapename;
    
    public:
    GeometricShape(){};

    void setShapeName(string name) const {
        shapename = name;
    }

    string getShapeName() const {
        return shapename;
    }
};

class Trigon : public GeometricShape {
    mutable double base, prependicular, hypotenuse;
    public:
    Trigon() : GeometricShape() {
        base = 1.0;
        prependicular = 1.0;
        hypotenuse = 1.0;
    };

    Trigon(double _base, double _prependicular, double _hypotenuse) : GeometricShape() {
        setBase(_base);
        setPrependicular(_prependicular);
        setHypotenuse(_hypotenuse);
    };

    void setBase(double _base) const {
        base = _base > 0 ? _base : 1.0;
    }

    void setPrependicular(double _prependicular) const {
        prependicular = _prependicular > 0 ? _prependicular : 1.0;
    }

    void setHypotenuse(double _hypotenuse) const {
        hypotenuse = _hypotenuse > 0 ? _hypotenuse : 1.0;
    }

    double getBase() const {
        return base;
    }

    double getPrependicular() const {
        return prependicular;
    }

    double getHypotenuse() const {
        return hypotenuse;
    }

    void displayArea() const {
        cout << "Area of " << shapename << " is " << (base * prependicular) / 2 << endl;
    }

};