#include <iostream>
using namespace std;

class BankAccount
{
public:

	int title;
	double balance;
	
	BankAccount()
	{
		title = 0;
		balance =0.0;
	}
	BankAccount(double b, int t)
	{
		t = title;
		b = balance;
	}
	~BankAccount()
	{
		cout << "Destructor called" << endl;
	}
	virtual void withdraw()
	{
		cout << "Bank Account withdraw" << endl;
		//	balance = balance - amount;
	}

	void deposit()
	{
		cout << "Bank Account deposit" << endl;
	}
};

class savingAccount : public BankAccount
{
public:
	
	void withdraw()
	{
		cout << "savingAccount withdraw" << endl;
	}
	void deposit()
	{
		cout << "savingAccount deposit" << endl;
	}
};

class currentAccount: public BankAccount
{
public:
	
	void withdraw()
	{
		cout << "currentAccount withdraw" << endl;
	}
	void deposit()
	{
		cout << "currentAccount deposit" << endl;
	}
};



int main()
{
	//BankAccount* s = new savingAccount(); //polymorphism
	//s->withdraw();

	int choice = 0;
	BankAccount* s1[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "press 1 for savings account, press 2 for current account." << endl;
		cin >> choice;
		if (choice == 1)
			s1[i] = new savingAccount();

		else if(choice ==2)
			s1[i] = new currentAccount();
		else
		{
			cout << "wrong output" << endl;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		s1[i]->withdraw();
	}

	for (int i = 0; i < 5; i++)
	{
		delete s1[i];
	}

	return 0;
}
/**
 * @brief ENGLISH PREP
 * 	T  T  T	 B  T  T  T  T  T  T   T   T   C   T   T   A   T   T   T   T   T   T   T   T   T    T   T   T   T   T
 * 1B 2A 3B 4C 5B 6A 7B 8B 9A 10B 11A 12B 13A 14C 15C 16B 17C 18B 19C 20B 21A 22C 23A 24B 25AB 26C 27C 28B 29C 30A  
 * HEDGING MEANS 
 *  
 */