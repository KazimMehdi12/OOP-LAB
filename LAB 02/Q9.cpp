#include<iostream>
using namespace std;

struct Product {
    int productID;
    char name[50];
    int quantity;
    double price;
};

int main(){
    int n;

    cout<<"Enter Number of Products: ";
    cin>>n;

    Product* inventory = new Product[n];

    for(int i=0; i<n; i++){
        cout<<"Detail For Product "<<i+1<<":"<<endl;
        cout<<"Enter Product ID: ";
        cin>>inventory[i].productID;
        cout<<"Enter Product Name: ";
        cin>>inventory[i].name;
        cout<<"Enter Quantity: ";
        cin>>inventory[i].quantity;
        cout<<"Enter Price: ";
        cin>>inventory[i].price;
    }   cout<<endl;

    double totalValue = 0;
    for(int i=0; i<n; i++){
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    cout<<"The Total Inventory: "<<totalValue<<endl;
    delete[] inventory;

}
