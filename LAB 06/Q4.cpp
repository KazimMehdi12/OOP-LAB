#include<iostream>
using namespace std;

class Account {
	public:
		int AccountNumber;
		float Balance;

		Account(int an,float b) {
			AccountNumber=an;
			Balance=b;
		}

		void displayDetails() {
			cout<<"Account Number: "<<AccountNumber<<"\nBalance: "<<Balance<<endl;
		}
};

class SavingsAccount : public Account {
	public:
		float InterestRate;

		SavingsAccount(int an,float b,float i):Account(an,b) {
			InterestRate=i;
		}

		void displayDetails() {
			Account::displayDetails();
			cout<<"Interest Rate: "<<InterestRate<<"%"<<endl;
		}
};

class CheckingAccount : public Account {
	public:
		float OverdraftLimit;

		CheckingAccount(int an,float b,float ol):Account(an,b) {
			OverdraftLimit=ol;
		}

		void displayDetails() {
			Account::displayDetails();
			cout<<"Overdraft Limit: "<<OverdraftLimit<<endl;
		}
};

int main() {
	int an;
	float b,interest,ol;

	cout<<"Enter Savings Account Number: ";
	cin>>an;
	cout<<"Enter Balance: ";
	cin>>b;
	cout<<"Enter Interest Rate: ";
	cin>>interest;
	SavingsAccount sa(an,b,interest);

	cout<<"\nEnter Checking Account Number: ";
	cin>>an;
	cout<<"Enter Balance: ";
	cin>>b;
	cout<<"Enter Overdraft Limit: ";
	cin>>ol;
	CheckingAccount ca(an,b,ol);

	cout<<"\nSavings Account Details:\n";
	sa.displayDetails();

	cout<<"\nChecking Account Details:\n";
	ca.displayDetails();

}
