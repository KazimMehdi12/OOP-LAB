#include<iostream>
#include<exception>
using namespace std;

class NegativeStockException : public exception {};

class OverCapacityException : public exception {};

template <typename T>
class InventoryItem{
	private:
		T stock;
		T maxCap;

	public:
		InventoryItem(T max) : stock(0), maxCap(max) {}

		void setStock(T val){
			if(val<0){
				throw NegativeStockException();
			}
			else if(val>maxCap){
				throw OverCapacityException();
			}
			stock = val;
		}

		T getStock() const{
			return stock;
		}
};

int main(){
	InventoryItem<int> item(100);

	try{
		cout<<"Set stock to -5\n";
		item.setStock(-5);
	}
	catch (const NegativeStockException& e){
		cout<<"Error NegativeStock: "<<e.what()<<"\n";
	}

	try{
		cout<<"Set stock to 120\n";
		item.setStock(120);
	}
	catch (const OverCapacityException& e){
		cout<<"Error OverCapacity: "<<e.what()<<"\n";
	}
}
