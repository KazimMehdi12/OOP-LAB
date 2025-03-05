#include<iostream>
using namespace std;

class Employee{
  public:
    string name;
    string designation;

    Employee(string n, string d){
        name = n;
        designation = d;
    }
};

class Project{
  public:
    string title;
    string deadline;
    Employee* employees[10];
    int Count = 0;

    Project(string t, string d){
        title = t;
        deadline = d;
    }

    void addEmployee(Employee* emp){
        if(Count < 10){
        	employees[Count++] = emp;
		}
    }

    void display(){
        cout<<"Project: "<<title<<"\nDeadline: "<<deadline<<"\nEmployees:"<<endl;
            for(int i=0; i<Count; i++){
               cout<<employees[i]->name<<" - "<<employees[i]->designation <<endl;
        }
    }
};

int main(){
    Employee e1("FAISAL", "Developer");
    Employee e2("ALI", "Designer");
    Employee e3("AHMED", "Manager");

    Project p1("Software Specialist", "15-04-2024");
    Project p2("AI Specialist", "20-05-2024");

    p1.addEmployee(&e1);
    p1.addEmployee(&e3);
    p2.addEmployee(&e2);
    p2.addEmployee(&e1);

    cout<<"Project Details:\n"<<endl;
    p1.display();
    cout<<endl;
    p2.display();
    
}
