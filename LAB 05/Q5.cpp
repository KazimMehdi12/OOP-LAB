#include<iostream>
using namespace std;

class Doctor{
	public:
		string name, specialization;
		int experience;

		Doctor(string n, string sp, int ex){
			name = n;
			specialization = sp;
			experience = ex;
		}

		void display(){
			cout<<"Doctor: "<<name<<" Specialization: "<<specialization
			<<" Experience: "<<experience<<" years "<<endl;
		}
};

class Hospital{
	public:
		string hospitalName;
		Doctor* doctors[10];
		int count;

		Hospital(string name){
			hospitalName = name;
			count = 0;
		}

		void addDoctor(Doctor* doc){
			if(count<10){
				doctors[count++] = doc;
			}
		}

		void display(){
			cout<<"Hospital: "<<hospitalName<<"\nDoctors: "<<endl;
			for(int i=0; i<count; i++){
				doctors[i]->display();
			}
		}
};

int main(){
	Hospital h("City Hospital");
	Doctor d1("Dr. Smith", "Cardiology", 10);
	Doctor d2("Dr. Lee", "Neurology", 8);
	h.addDoctor(&d1);
	h.addDoctor(&d2);
	h.display();
	
}
