#include<iostream>
#include<string>
using namespace std;

class Car;
class InventoryManager{
	public:
		void updatePrice(Car& c, double newPrice);
		void displayCar(const Car& c);
};

class Car{
	private:
		string model;
		double price;

	public:
		Car(string m, double p){
			model = m;
			price = p;
		}

		friend class InventoryManager;
		friend void comparePrice(const Car& c1, const Car& c2);
};

  void InventoryManager::updatePrice(Car& c, double newPrice){
 	 c.price = newPrice;
}

  void InventoryManager::displayCar(const Car& c){
	 cout<<"Model: "<<c.model<<"- Price: "<<c.price<<endl;
}

  void comparePrice(const Car& c1, const Car& c2){
	 if(c1.price > c2.price){
		cout<<c1.model<<" :more expensive."<<endl;
	} 
	else if(c2.price > c1.price){
		cout<<c2.model<<" :more expensive."<<endl;
	} 
	else{
		cout<<"Both have same price"<<endl;
	}
}

int main(){
	Car car1("Toyota", 30000);
	Car car2("Honda", 19000);

	InventoryManager manager;
	manager.displayCar(car1);
	manager.displayCar(car2);

	manager.updatePrice(car2, 25000);
	cout<<"After price update:"<<endl;
	manager.displayCar(car2);

	comparePrice(car1, car2);
  
}
