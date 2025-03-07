#include<iostream>
using namespace std;

class Device{
	public:
		int DeviceID;
		bool Status;

		Device(int i, bool s){
			DeviceID = i;
			Status = s;
		}

		void displayDetails(){
			cout<<"Device ID: "<<DeviceID<<endl;
			  if(Status){
			  	cout<<"Status: On"<<endl;
			  }
		   	  else{
		   	  	cout<<"Status: Off"<<endl;
				}
		}
};

class SmartPhone : public Device{
	public:
		float ScreenSize;

		SmartPhone(int i, bool s, float ss) : Device(i, s) {
			ScreenSize = ss;
		}

		void displayDetails(){
			Device::displayDetails();
			cout<<"Screen Size: "<<ScreenSize<<" inches"<<endl;
		}
};

class SmartWatch : public SmartPhone{
	public:
		bool HeartRateMonitor;

		SmartWatch(int i, bool s, float ss, bool hrm) : SmartPhone(i, s, ss) {
			HeartRateMonitor = hrm;
		}

		void displayDetails(){
			SmartPhone::displayDetails();
			if(HeartRateMonitor){
				cout<<"Heart Rate Monitor: Yes"<<endl;
			}
			else{
				cout<<"Heart Rate Monitor: No"<<endl;
			}
		}
};

class SmartWearable : public SmartWatch{
	public:
		int StepCounter;

		SmartWearable(int id, bool s, float ss, bool hrm, int sc) : SmartWatch(id, s, ss, hrm){
			StepCounter = sc;
		}

		void displayDetails(){
			SmartWatch::displayDetails();
			cout<<"Step Counter: "<<StepCounter<<endl;
		}
};

int main(){
	int i, steps;
	bool status, hrm;
	float screenSize;

	cout<<"Enter Device ID: ";
	cin>>i;
	cout<<"Enter Status (1,0): ";
	cin>>status;
	cout<<"Enter Screen Size: ";
	cin>>screenSize;
	cout<<"Enter Heart Rate Monitor (1,0): ";
	cin>>hrm;
	cout<<"Enter Step Counter: ";
	cin>>steps;

	SmartWearable s(i, status, screenSize, hrm, steps);
	s.displayDetails();

}
