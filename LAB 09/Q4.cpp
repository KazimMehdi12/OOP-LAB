#include<iostream>
using namespace std;

class WeatherSensor{
	public:
		virtual void readData() = 0;
		virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor{
		float temperature;
	public:
		void readData(){
			temperature = 20.5;
		}

		void displayReport(){
			cout<<"Thermometer Reading: "<<temperature<<" C"<<endl;
		}
};

class Barometer : public WeatherSensor{
		float pressure;
	public:
		void readData(){
			pressure = 500.5;
		}

		void displayReport(){
			cout<<"Barometer Reading: "<<pressure<<endl;
		}
};

int main(){
	WeatherSensor* s1 = new Thermometer();
	WeatherSensor* s2 = new Barometer();

	s1->readData();
	s1->displayReport();
	cout<<endl;
	s2->readData();
	s2->displayReport();

	delete s1;
	delete s2;

}
