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
	/**
	 * @brief simplifies the fraction
	 * for instance 1/2 -> 1/2 and 2/4 -> 1/2
	 * @return void
	 * @param void
	 * @pre the fraction must be initialized
	 *  
	 */
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
	/**
	 * @brief Construct a new Fraction object
	 */
	Fraction() {
		num = 1;
		den = 1;
	}
	/**
	 * @brief Construct a new Fraction object
	 * 
	 * @param n numerator
	 */
	Fraction(int n){
		num = n;
		den = 1;

	}
	/**
	 * @brief Construct a new Fraction object
	 * 
	 * @param n numerator
	 * @param d denominator
	 */
	Fraction(int n, int d) {
		num = n;
		den = d > 0 ? d : 1;
	}
	// copy constructor
	Fraction(const Fraction& f) {
		num = f.num;
		den = f.den;
		cout << "copy constructor" << endl;
	}
	// 
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
	Fraction& operator ++(){
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

	// 02-12-2021

	// friend ostream& operator<<(ostream& out,const Fraction& fraction){
	// 	out << fraction.num << "\\" << fraction.den;
	// 	return out;
	// }
	// friend istream& operator>>(istream& in,Fraction& fraction){
	// 	cout << "Enter Numerator: ";
	// 	in >> fraction.num;
	// 	cout << "Enter Denominator: ";
	// 	in >> fraction.den;
	// 	return in;
	// };

    void simplify(){
        normalize();
    }

	int getNumerator(){
		return num;
	}

	int getDenominator(){
		return den;
	}

	void setNumerator(int val){
		num = val;
	}

	void setDenominator(int val){
		den = val;
	}
};

ostream& operator <<(ostream& out,Fraction& f){
	out << f.getNumerator() << "\\" << f.getDenominator();
	return out;
}
istream& operator>>(istream& in,Fraction& fraction){
	int temp;
	cout << "Enter Numerator: ";
	in >> temp;
	fraction.setNumerator(temp);
	cout << "Enter Denominator: ";
	in >> temp;
	fraction.setDenominator(temp);
	return in;
};

// create a class for queue
class Queue
{
	int *arr;
	int front;
	int rear;
	int size;
	int capacity;

	void resize(){
		int *temp = new int[capacity * 2];
		for (size_t i = 0; i < capacity; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity *= 2;
	}
public:
	Queue(int cap) {
		capacity = cap;
		arr = new int[capacity];
		front = 0;
		rear = 0;
		size = 0;
	}
	~Queue() {
		delete[] arr;
	}
	void enqueue(int val) {
		if (size == capacity)
		{
			resize();
		}
		arr[rear] = val;
		rear = (rear + 1) % capacity;
		size++;
	}
	int dequeue() {
		if (size == 0)
		{
			return -1;
		}
		int val = arr[front];
		front = (front + 1) % capacity;
		size--;
		return val;
	}
	int frontValue() {
		if (size == 0)
		{
			return -1;
		}
		return arr[front];
	}
	int rearValue() {
		if (size == 0)
		{
			return -1;
		}
		return arr[rear];
	}
	int sizeOfQueue() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == capacity;
	}
};

// create a class for stack


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
	cin >> f1;
	cout << "POST FIX:";
	cout << f1;
	cout << "PRE FIX:" << ++++f1 << endl;
	cout << f1;
	// cout << ++++1;
	// cout << 1++++;


	return 0;
}