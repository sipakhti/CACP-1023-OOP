#include <iostream>
using namespace std;

class Fraction
{
	int num;
	int den;
    void invert(){
        int temp = num;
        num = den;
        den = temp;
    }
    void normalize(){
        for (size_t i = 2; i <= num && i <= den; i++)
        {
            if (num % i == 0 && den % i == 0)
                {
                    num /= i;
                    den /= i;
                }
        }
        
    }

public:

	Fraction() {
		num = 0;
		den = 1;
	}
	Fraction(int n){
		num = n;
		den = 1;

	}
	Fraction(int n, int d) {
		num = n;
		den = d > 0 ? d : 1;
	}
	Fraction operator +(Fraction f2)
	{
		Fraction f3;

		f3.num = (num * f2.den) + (f2.num * den);

		f3.den = den * f2.den;	
		f3.simplify();
		return f3;
	}
	Fraction operator -(Fraction f2)
	{
		Fraction f3;

		f3.num = (num * f2.den) - (f2.num * den);

		f3.den = den * f2.den;	
		f3.simplify();
		return f3;
	}
	Fraction operator *(Fraction f2)
	{
		Fraction f3;

		f3.num = num * f2.num;

		f3.den = den * f2.den;	
		f3.simplify();
		return f3;
	}
	Fraction operator /(Fraction f2)
	{
        f2.invert();
        Fraction f3 = *this * f2;
		f3.simplify();
        return f3;

	}
	Fraction operator ++(){
		Fraction fraction(1);
		*this = *this + fraction;
		return *this;
	}
	Fraction operator ++(int){
		Fraction fraction(1);
		Fraction temp = *this;
		*this = *this + fraction;
		return temp;
	}
	void operator --(){
		Fraction fraction(1);
		*this = *this - fraction;
	}
	void operator --(int){
		Fraction fraction(1);
		*this = *this - fraction;
	}
	void display()
	{
		cout << num << "\\" << den << endl;
	}

	friend ostream& operator<<(ostream& out,const Fraction& fraction){
		out << fraction.num << "\\" << fraction.den;
		return out;
	}
	friend istream& operator>>(istream& in,Fraction& fraction){
		cout << "Enter Numerator: ";
		in >> fraction.num;
		cout << "Enter Denominator: ";
		in >> fraction.den;
		return in;
	};

    void simplify(){
        normalize();
    }
};
int main() {
	Fraction f1(5, 3); //f1
	Fraction f2(3); //f2=5/4	

	// f1.display();
	// f2.display();
    // f2.simplify();
    // f2.display();
	Fraction f3;

	f3 = f1 * f2;
	f3.display();
    // f2.display();
	f3.display();
	
	cout << "POST FIX:" << ++f1 << endl;
	cout << "PRE FIX:" << f1++ << endl;
	cout << f1;


	return 0;
}