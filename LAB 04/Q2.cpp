#include<iostream>
#include<string>
using namespace std;

class Car{
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;

public:
    Car(){
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        isAvailable = true;
    }

    Car(string b, string m, double p, bool IA){
        brand = b;
        model = m;
        rentalPrice = p;
        isAvailable = IA;
    }

    double ApplyDiscount(int days){
        double discount = 0.0;
        if(days >= 5 && days < 10) {
            discount = rentalPrice * 0.05 * days;
        } 
		else if(days >= 10) {
            discount = rentalPrice * 0.1 * days;
         }
        return (rentalPrice*days) - discount;
    }

    void InputforUpdate(){
        cout<<"Values For Updating:\n";
        cout<<"Enter brand: ";
        cin>>brand;
        cout<<"Enter Model: ";
        cin>>model;
        cout<<"Enter Rental Price: ";
        cin>>rentalPrice;
    }

    void Availability(){
        if (isAvailable){
            cout<<"\nCar is available for rent "<<endl;
        } 
		else {
            cout<<"\nCar is already rented "<<endl;
        }
    }

    void rentCar(int days){
        if(isAvailable){
            isAvailable = false;
            double finalPrice = ApplyDiscount(days);
            cout<<"\nCar rented successfully for "<<days<<" days "<<endl;
            cout<<"Total cost after discount: "<<finalPrice<<endl;
        } else {
            cout<<"Car is already rented "<<endl;
        }
    }

    void returnCar(){
        isAvailable = true;
        cout<<"\nCar returned successfully "<<endl;
    }

    void ShowInfo(){
        cout<<"\nCar Details:\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price per day: "<<rentalPrice<<endl;
    }
};

int main() {
    Car c1("Toyota", "GLI", 4000, true);
    Car c2("Honda", "City", 5500, true);

    c1.ShowInfo();
    cout<<endl;
    c2.ShowInfo();

    c1.rentCar(7);
    cout<<"\nAttempting to rent the same car again "<<endl;
    c1.rentCar(4);

    c1.returnCar();

    cout<<"\nRenting car for 12 days "<<endl;
    c1.rentCar(12);

}
