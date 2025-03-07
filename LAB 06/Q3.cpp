#include<iostream>
using namespace std;

class Person{
	public:
		string name;
		int age;
		
		Person(string n, int a){
			name = n;
			age = a;
		}
		
		void display(){
			cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
		}
};

class Teacher : public Person{
	public:
		string subject;
		
		Teacher(string n, int a, string sub) : Person(n,a){
			subject = sub;
		}
		
		void display(){
			Person::display();
			cout<<"Subject: "<<subject<<endl;
		}
};

class Research : public Teacher{
	public:
		string researchArea;
		
		Research(string n, int a, string sub, string rA) : Teacher(n,a,sub){
			researchArea = rA;
		}
		
		void display(){
			Teacher::display();
			cout<<"Research Area: "<<researchArea<<endl;
		}
};

class Professor : public Teacher , public Research{
	public:
		int Publications;
		
		Professor(string n, int a, string sub, string rA, int pb) : Teacher(n,a,sub), Research(n,a,sub,rA){
			Publications = pb;
		}
		
		void display(){
			Research::display();
			cout<<"Publication: "<<Publications<<endl;
		}
};

int main(){
	string name, subject, researchArea;
	int age, Publications;
	
	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter Age: ";
	cin>>age;	
	cout<<"Enter Subject: ";
	cin>>subject;
	cout<<"Enter Research Area: ";
	cin>>researchArea;
    cout<<"Enter Publication: ";
	cin>>Publications;
	
	Professor p1(name,age,subject,researchArea,Publications);
	p1.display();
}
