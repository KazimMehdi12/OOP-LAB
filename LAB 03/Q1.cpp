#include<iostream>
#include<string>
using namespace std;

class Wallet{
	public:
	string Ownername;
	float TotalBalance = 0; 
	string TransactionHistory[20];
	
	void show(){
		int choice;
           cout<<"What do you want to do?\n";
           cout<<"1. Add Money\n";
           cout<<"2. Spend Money\n";
           cout<<"3. Check Balance\n";
           cout<<"4. Exit\n";
           cout<<"Enter your choice: ";
           cin>>choice;

   switch(choice){
     case 1:
        addMoney();
        break;
     case 2:
        spendMoney();
        break;
     case 3:
        CheckBalance();
        break;
     case 4:
        cout<<"Goodbye \n";
        break;
     default:
        cout<<"Invalid choice. Please try again.\n";
    }
}

	void addMoney(){
        double amount;
        cout<<"Enter Amount To Add: ";
        cin>>amount;
        TotalBalance += amount;
    }
    
    void spendMoney(){
        double amount;
        cout<<"Enter amount to spend: ";
        cin>>amount;
        if(amount > 0 && amount <= TotalBalance) {
            TotalBalance -= amount;
        } 
		else {
            cout<<"Invalid Amount.\n";
        }
    }
    
    void CheckBalance(){
    	cout<<"Current Balance is :"<<TotalBalance<<endl;
	}
};

int main(){
	Wallet ob1;
	ob1.show();
	ob1.addMoney();
	ob1.addMoney();
	ob1.CheckBalance();
}
