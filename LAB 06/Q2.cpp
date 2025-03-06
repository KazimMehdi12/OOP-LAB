#include<iostream>
using namespace std;

class Vehicle{
	public:
		string brand;
		int speed;
        
        Vehicle(string b, int sp){
        	brand = b;
        	speed = sp;		
		}
        
        void displayDetail(){
      	  cout<<"Brand: "<<brand<<"\nSpeed: "<<speed<<endl;
      	
	  }
};

class Car : public Vehicle{
	public:
		int seats;
		
		Car(string b, int sp, int st) : Vehicle(b,sp) {
			seats = st;
		}
		
		void displayDetail(){
		    Vehicle::displayDetail();
			cout<<"Seat: "<<seats<<endl;
		}
};

class ElectricCar : public Car{
	public:
		int batteryLife;
		
		ElectricCar(string b, int sp, int st, int bL) : Car(b,sp,st){
			batteryLife = bL;
		}
		
		void displayDetail(){
			Car::displayDetail();
			cout<<"Battery Life: "<<batteryLife;
			
		}
};

int main(){
	int speed , batteryLife, seats;
	string brand;
	
	cout<<"Enter Brand: ";
	cin>>brand;
	cout<<"Enter Seats: ";
	cin>>seats;
	cout<<"Enter Speed: ";
	cin>>speed;
	cout<<"Enter Battery Life: ";
	cin>>batteryLife;
	cout<<endl;
	
	ElectricCar c1(brand,speed,seats,batteryLife);
	c1.displayDetail();
	
}
