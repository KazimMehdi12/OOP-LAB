#include<iostream>
using namespace std;

class Account;
class Manager {
	public:
		void showAccount(Account a);
		void deposit(Account &a, float amt);
		void withdraw(Account &a, float amt);
};

class Account{
	private:
		int number;
		float balance;

	public:
		Account(){
			number = 0;
			balance = 0;
		}

		Account(int n, float b){
			number = n;
			balance = b;
		}
		
		friend void transferFunds(Account &from, Account &to, float amt);
		friend class Manager;
};

  void Manager::showAccount(Account a){
	cout<<"Account No: "<<a.number<<"and Balance: "<<a.balance<<endl;
}

  void Manager::deposit(Account &a, float amt){
	a.balance += amt;
	cout<<"Deposited "<<amt<<" to Account "<<a.number<<endl;
}

  void Manager::withdraw(Account &a, float amt){
	if(amt <= a.balance){
		a.balance -= amt;
		cout<<"Withdraw "<<amt<<" from account "<<a.number<<endl;
	} 
	else{
		cout<<"Insufficient balance "<<a.number<<endl;
	}
}

  void transferFunds(Account &from, Account &to, float amt){
	if(amt <= from.balance){
		from.balance -= amt;
		to.balance += amt;
		cout<<"Transferred "<<amt<<" from account "<<from.number;
		cout<<" to Account"<<to.number<<endl;
	}
	else{
		cout<<"Insufficient balance"<<from.number<<endl;
	}
}

int main(){
	Account a1(1, 1000);
	Account a2(2, 500);
	Manager m;

	m.showAccount(a1);
	m.showAccount(a2);
	m.deposit(a1, 200);
	m.withdraw(a2, 100);
	transferFunds(a1, a2, 300);
	m.showAccount(a1);
	m.showAccount(a2);
}
