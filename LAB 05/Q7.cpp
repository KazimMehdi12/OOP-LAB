#include<iostream>
using namespace std;

class Product{
	public:
		int id, quantity;
		string name;

		Product(int i, string n, int q){
			id = i;
			name = n;
			quantity = q;
		}

		void display(){
			cout<<"ID: "<<id<<"  Name: "<<name<<"  Quantity: "<<quantity<<endl;
		}
};

class Warehouse{
	public:
		Product* inventory[20];
		int count;

		Warehouse(){
			count = 0;
		}

		void addProduct(int i, string n, int q) {
			if(count<20){
				inventory[count++] = new Product(i, n, q);
			}
		}

		void sortByName(){
			for(int i=0; i<count-1; i++){
				for(int j=0; j<count-i-1; j++){
					if(inventory[j]->name>inventory[j+1]->name){
						Product* temp = inventory[j];
						inventory[j] = inventory[j+1];
						inventory[j+1] = temp;
					}
				}
			}
		}

		void searchByID(int searchID){
			for(int i=0; i<count; i++) {
				if(inventory[i]->id == searchID){
					inventory[i]->display();
					return;
				}
			}
			cout<<"Product not found "<<endl;
		}

		void displayAll(){
			cout<<"Warehouse Inventory: "<<endl;
			for(int i=0; i<count; i++){
				inventory[i]->display();
			}
		}

		~Warehouse(){
			for(int i=0; i<count; i++){
				delete inventory[i];
			}
		}
};

int main() {
	Warehouse w;
	w.addProduct(33, "Android", 5);
	w.addProduct(36, "Laptop", 4);
	w.addProduct(42, "Apples", 9);

	cout<<"Before Sorting: "<<endl;
	w.displayAll();

	w.sortByName();
	cout<<"\nAfter Sorting: "<<endl;
	w.displayAll();

	cout<<"\nSearch for Product ID 44: "<<endl;
	w.searchByID(33);

}
