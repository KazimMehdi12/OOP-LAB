#include<iostream>
using namespace std;

class Car{
  private:
     string brand;
     string model;
     int fuelCapacity;
     int currentFuelLevel;

  public:
    void Initialize(string b, string m, int c){
        brand = b;
        model = m;
        fuelCapacity = c;
        currentFuelLevel = c;
      }

    void drive(int distance){
        int fuelUsed = distance/10;
        if(currentFuelLevel >= fuelUsed){
            currentFuelLevel -= fuelUsed;
        } 
		else{
            cout<<"Not Fuel "<<endl;   }
    }

    void refuel(int amount){
        if(currentFuelLevel + amount <= fuelCapacity) {
            currentFuelLevel += amount;
        } 
		else{
            currentFuelLevel = fuelCapacity;
        }
    }

    void checkFuel(){
        cout<<"Car: "<<brand<<" "<<model<<endl;
        cout<<"Current Fuel Level: "<<currentFuelLevel<<" liters"<<endl;
        if(currentFuelLevel < 5){
            cout<<"Please Refuel "<<endl;
        }
    }
};

int main() {
    Car zc;
    zc.Initialize("Honda", "Civics", 50);
    zc.drive(120);
    zc.checkFuel();
    zc.refuel(30);
    zc.checkFuel();
    return 0;
}
