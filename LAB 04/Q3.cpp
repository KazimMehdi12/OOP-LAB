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
        
        Car(const Car &obj){
            brand = obj.brand;
            model = obj.model;
            rentalPrice = obj.rentalPrice;
            isAvailable = obj.isAvailable;
            cout<<"Car Copied"<<endl;
        }
        
        ~Car(){
            cout<<"Car Object Destroyed"<<endl;
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
    
    void rentCar(){
        if(isAvailable){
            isAvailable = false;
            cout<<"\nCar rented Successfully "<<endl; 
        } 
        else{
            cout<<"Car is not Available \n";
        }
    }
    
    void ShowInfo(){
        cout<<"\nUpdated Information:"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price: "<<rentalPrice<<endl;
        cout<<"Availability: ";
        if(isAvailable)
            cout<<"Available"<<endl;
        else
            cout<<"Rented"<<endl;
    }
};

int main(){
    Car ob1;
    ob1.InputforUpdate();
    ob1.ShowInfo();
    
    Car ob2 = ob1;
    cout<<"\nCopied Car Details:"<<endl;
    ob2.ShowInfo();
    
    ob1.InputforUpdate();
    cout<<"\nAfter Modifying:"<<endl;
    ob1.ShowInfo();
    
    cout << "\nCopied Car Details Remain Unchanged:" << endl;
    ob2.ShowInfo();
    
    return 0;
}
