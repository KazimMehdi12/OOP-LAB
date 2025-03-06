#include<iostream>
using namespace std;

class AlarmSystem{
	public:
		string securityLevel;

		AlarmSystem(string L){
			securityLevel = L;
		}

		void display(){
			cout<<"Alarm Security Level: "<<securityLevel<<endl;
		}
};

class SmartHome{
	public:
		AlarmSystem alarm;

		SmartHome(string L) : alarm(L) {}
		
		void display(){
			alarm.display();
		}
};

int main(){
	SmartHome h("High");
	h.display();
	
}
