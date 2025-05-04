#include<iostream>
#include<fstream>
using namespace std;

struct InventoryItem{
	int itemID;
	char itemName[20];
};

int main(){
	InventoryItem item;

	cout<<"Enter Item ID: ";
	cin>>item.itemID;

	cout<<"Enter Item Name: ";
	cin>>item.itemName;

	ofstream outFile("inventory.dat", ios::binary);  // Write to binary file
	if (!outFile){
		cout<<"Error in opening file for writing"<<endl;
		return 1;
	}
	outFile.write(reinterpret_cast<char*>(&item), sizeof(item));
	outFile.close();

	InventoryItem readItem;   // Read from binary file
	ifstream inFile("inventory.dat", ios::binary);
	
	if(!inFile){
		cout<<"Error in opening file for reading"<<endl;
		return 1;
	}
	
	inFile.read(reinterpret_cast<char*>(&readItem), sizeof(readItem));
	inFile.close();

	cout<<"Read from file:"<<endl;
	cout<<"Item ID: " <<readItem.itemID<<endl;
	cout<<"Item Name: "<<readItem.itemName<<endl;

	return 0;
}
