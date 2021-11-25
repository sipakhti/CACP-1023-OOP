#include <iostream>
using namespace std;

class Fraction
{
	int num;
	int den;

public:

	Fraction() {
		num = 0;
		den = 1;
	}
	Fraction(int n, int d) {
		num = n;
		if (d > 0)
			den = d;
		else
			den = 1;
	}
	Fraction operator +(Fraction f2)
	{
		Fraction f3;

		f3.num = (num * f2.den) + (f2.num * den);

		f3.den = den * f2.den;	

		return f3;
	}
	Fraction operator -(Fraction f2)
	{
		Fraction f3;

		f3.num = (num * f2.den) - (f2.num * den);

		f3.den = den * f2.den;	

		return f3;
	}
	Fraction operator *(Fraction f2)
	{
		Fraction f3;

		f3.num = num * f2.num;

		f3.den = den * f2.den;	

		return f3;
	}
	Fraction operator /(Fraction f2)
	{
        f2.invert();
        Fraction f3 = *this * f2;
        return f3;
        return *this * f2;

	}

    void invert(){
        int temp = num;
        num = den;
        den = temp;
    }
	void display()
	{
		cout << num << "\\" << den << endl;
	}
};
int main() {
	Fraction f1(1, 2); //f1
	Fraction f2(3, 4); //f2=5/4	

	f1.display();
	f2.display();
	Fraction f3;

	f3 = f1 / f2;
	f3.display();
    f2.display();
	return 0;
}