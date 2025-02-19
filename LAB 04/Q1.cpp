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
        
    void InputforUpdate(){
        cout<<"Values For Updating: \n";
        cout<<"Enter brand: ";
        cin>>brand;
        cout<<"Enter Model: ";
        cin>>model;
        cout<<"Enter Rental Price: ";
        cin>>rentalPrice;
    }    
    
    void Availability(){
        if(isAvailable){
            cout<<"\nCar is Available for Rent"<<endl;
        }
        else{
            cout<<"\nCar is Already Rented "<<endl; 
        }
    }
    
    void rentCar(){
        if(isAvailable){
            isAvailable = false;
            cout<<"\nCar rented Successfully \n"; 
        } 
        else{
            cout<<"Car is not Available \n";
        }
    }
    
    void ShowInfo(){
        cout<<"\nUpdated Information is"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price: "<<rentalPrice<<endl;
        if(isAvailable)
            cout <<"\nAvailable"<<endl;
        else
            cout<<"\nNot Available"<<endl;
    }
};

int main(){
    Car ob1;
    
    ob1.InputforUpdate();
    ob1.ShowInfo();
    ob1.rentCar();
    ob1.ShowInfo();
    
    return 0;
}
