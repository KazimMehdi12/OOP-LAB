#include<iostream>
using namespace std;

class Employee{
	public:
		string name;
		float salary;
		
		Employee(string n , float s){
			name = n;
			salary = s;
		}
		
		void displayDetail(){
			cout<<"Name of Employee is: "<<name<<endl;
			cout<<"Salary of Employee is: "<<salary<<endl;
		}	
};

class Manager : public Employee{
	public:
	    float bonus;
	   
		Manager(string n, float s, float b) : Employee(n, s){
        bonus = b;
    }
    
    void displayDetail(){
        cout<<"Name: "<<name<<"\nSalary: "<<salary<<"\nBonus: "<<bonus<<endl;
    }
};

int main(){
	string name;
	float salary, bonus;
	
	cout<<"Enter Manager Name: ";
    cin>>name;
    cout<<"Enter Salary: ";
    cin>>salary;
    cout<<"Enter Bonus: ";
    cin>>bonus;
	
	Manager m(name, salary, bonus);
	m.displayDetail();
}
